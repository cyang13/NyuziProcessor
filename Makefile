#
# Copyright 2011-2015 Jeff Bush
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#


JAVAC := $(shell which javac)

all:
	cd tools/emulator && make
	cd tools/serial_boot && make
	cd tools/mkfs && make
	cd hardware/ && make
	cd software/ && make
ifneq ($(JAVAC),)
	cd tools/visualizer && make
endif

test: all
	cd tests/ && make test
	cd hardware && make fpgalint

clean:
	cd tools/emulator && make clean
	cd tools/serial_boot && make clean
	cd tools/mkfs && make clean
ifneq ($(JAVAC),)
	cd tools/visualizer && make clean
endif
	cd hardware/ && make clean
	cd software/ && make clean
	rm -rf bin/

FORCE:

