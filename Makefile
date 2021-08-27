build:
	mkdir -p $@ ; cd $@ ; cmake ..
	make -C $@

.PHONY: test
test: install
	python python/tests/test.py

.PHONY: install
install: clean
	pip install -e .

.PHONY: clean
clean:
	$(RM) -r sfst.egg-info/ sfst.*.so build/
