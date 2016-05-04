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

#include "libc.h"
#include "mmu.h"

// XXX need a global variable for _end to be emitted correctly.
int foo;

void kernel_main()
{
    mmu_finish_init();

    kprintf("Hello kernel land\n");

    // Start other threads
    *((volatile unsigned int*) 0xffff0100) = 0xdeadbeef;

    for (;;)
        ;
}

void thread_n_main()
{
    kprintf("%d\n", __builtin_nyuzi_read_control_reg(0));
    for (;;)
        ;
}

