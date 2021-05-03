import os
import sfst

CURR_DIR = os.path.abspath(os.path.dirname(os.path.realpath(__file__)))

easy_transducer = sfst.CompactTransducer(os.path.join(CURR_DIR, 'easy.ca'))
analysis_results = easy_transducer.analyse("easy")
assert len(analysis_results) == 1
assert analysis_results[0] == 'easy<ADJ><pos>'
