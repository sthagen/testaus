.DEFAULT_GOAL := all
build_coverage=build-coverage
build_release_with_debug=build
warning_policy=-Wno-dev
generator=Ninja
browser=open

.PHONY: setup
setup: clean
	pip install -r test/requirements.txt
	cmake -G $(generator) -DCMAKE_BUILD_TYPE=Coverage -S . -B $(build_coverage) $(warning_policy)
	cmake -G $(generator) -DCMAKE_BUILD_TYPE=ReleaseWithDeb -S . -B $(build_release_with_debug) $(warning_policy)

.PHONY: build
build:
	cmake --build $(build_release_with_debug) --target implementation
	cmake --build $(build_coverage) --target implementation

.PHONY: test
test:
	cmake --build $(build_coverage) --target execute_tests

.PHONY: coverage
coverage:
	cmake --build $(build_coverage) --target coverage
	@$(browser) $(build_coverage)/coverage/coverage_details.html
	@cat $(build_coverage)/coverage/summary_coverage.json && echo

.PHONY: analysis
analysis:
	cmake --build $(build_coverage) --target analysis
	@python -m json.tool $(build_coverage)/analysis/cppcheck.report.json

.PHONY: all
all: build example coverage analysis

.PHONY: example
example:
	cmake --build $(build_release_with_debug) --target example
	@echo "1 2 3" | $(build_release_with_debug)/example

.PHONY: clean
clean:
	@if [ -d "$(build_release_with_debug)" ]; then cmake --build $(build_release_with_debug) --target clean; fi
	@if [ -d "$(build_coverage)" ]; then cmake --build $(build_coverage) --target clean; fi

.PHONY: distclean
distclean:
	@rm -fr ./$(build_coverage) ./$(build_release_with_debug)

.PHONY: name
name:
	@printf "Release '%s'\n\n" "$$(git-release-name "$$(git rev-parse HEAD)")"
	@printf "%s revision.is(): sha1:%s\n" "-" "$$(git rev-parse HEAD)"
	@printf "%s name.derive(): '%s'\n" "-" "$$(git-release-name "$$(git rev-parse HEAD)")"
	@printf "%s node.id(): '%s'\n" "-" "$$(bin/gen_node_identifier.py)"
