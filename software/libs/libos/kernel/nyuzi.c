//
// Copyright 2016 Jeff Bush
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "syscall.h"

int get_current_thread_id(void)
{
    return __syscall(2, 0, 0, 0, 0, 0);
}

unsigned int get_cycle_count(void)
{
    return 0;   // XXX not implemented
}

void *create_area(unsigned int address, unsigned int size, int placement,
                  const char *name, int flags)
{
    return (void*) __syscall(6, 0, size, placement, (int) name, flags);
}