#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <memory>
#include <sstream>

#include "../src/fst.h"
#include "../src/compact.h"

using namespace std;
using namespace SFST;

class CustomTransducer : public SFST::Transducer
{
  public:
    CustomTransducer(FILE* f);
    static unique_ptr<CustomTransducer> create(char* filename);
    vector<string> analyse(char *input);
    vector<string> generate(char *input);
};

CustomTransducer::CustomTransducer(FILE* f)
  : SFST::Transducer(f)
{
}

unique_ptr<CustomTransducer> CustomTransducer::create(char* filename)
{
    FILE* f = fopen(filename, "rb");
    if (f != NULL)
    {
      auto transducer = unique_ptr<CustomTransducer>(new CustomTransducer(f));
      fclose(f);
      return transducer;
    }
    return unique_ptr<CustomTransducer>(nullptr);
}

vector<string> CustomTransducer::analyse(char *input)
{
  return analyze_string(input);
}

vector<string> CustomTransducer::generate(char *input)
{
  return generate_string(input, true);
}

class CustomCompactTransducer : public SFST::CompactTransducer
{
public:
  CustomCompactTransducer(FILE* f);
  static unique_ptr<CustomCompactTransducer> create(char* filename);
  vector<string> analyse(char *input);
  vector<string> generate(char *input);
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

PYBIND11_MODULE(sfst_transduce, m)
{
  py::class_<CustomTransducer>(m, "Transducer")
    .def(py::init(&CustomTransducer::create))
    .def("analyse", &CustomTransducer::analyse)
    .def("generate", &CustomTransducer::generate);

   py::class_<CustomCompactTransducer>(m, "CompactTransducer")
    .def(py::init(&CustomCompactTransducer::create))
    .def("analyse", &CustomCompactTransducer::analyse)
    .def_readwrite("both_layers", &CustomCompactTransducer::both_layers)
    .def_readwrite("simplest_only", &CustomCompactTransducer::simplest_only);
}
