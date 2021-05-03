#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <memory>
#include <sstream>

#include "../src/compact.h"

using namespace std;
using namespace SFST;

class CustomCompactTransducer : public SFST::CompactTransducer
{
  public:
    CustomCompactTransducer(FILE* f);
    static unique_ptr<CustomCompactTransducer> create(char* filename);
    vector<string> analyse(char *input);
};

CustomCompactTransducer::CustomCompactTransducer(FILE* f)
  : SFST::CompactTransducer(f)
{
}

unique_ptr<CustomCompactTransducer> CustomCompactTransducer::create(char* filename)
{
    FILE* f = fopen(filename, "rb");
    if (f != NULL)
    {
      auto transducer = unique_ptr<CustomCompactTransducer>(new CustomCompactTransducer(f));
      fclose(f);
      return transducer;
    }
    return unique_ptr<CustomCompactTransducer>(nullptr);
}

vector<string> CustomCompactTransducer::analyse(char *input)
{
  vector<CAnalysis> analyses;
  analyze_string(input, analyses);

  vector<string> printed_analyses;
  for (auto& analysis : analyses)
  {
    string printed_analysis = print_analysis(analysis);
    printed_analyses.push_back(printed_analysis);
  }
  return printed_analyses;
}

namespace py = pybind11;

PYBIND11_MODULE(sfst, m)
{
  py::class_<CustomCompactTransducer>(m, "CompactTransducer")
    .def(py::init(&CustomCompactTransducer::create))
    .def("analyse", &CustomCompactTransducer::analyse)
    .def_readwrite("both_layers", &CustomCompactTransducer::both_layers)
    .def_readwrite("simplest_only", &CustomCompactTransducer::simplest_only);
}
