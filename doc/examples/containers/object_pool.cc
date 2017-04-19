/*
 * Copyright (c) 2014-2017, Siemens AG. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include<iostream>
#include<embb/containers/object_pool.h>
#include<embb/containers/lock_free_tree_value_pool.h>

void RunObjectPoolExample1() {
  // snippet_begin:object_pool
  embb::containers::ObjectPool<int> objPool(5); // create

  int* alloc[5];

  for (int i = 0; i != 5; ++i) {
    alloc[i] = objPool.Allocate(); // allocate
  }

  for (int i = 0; i != 5; ++i) {
    objPool.Free(alloc[i]); // free
  }
  // snippet_end
}

void RunObjectPoolExample2() {
  // snippet_begin:object_pool_2
  embb::containers::ObjectPool<int, 
    embb::containers::LockFreeTreeValuePool< int, 0 >> objPool(5); // create
  // snippet_end
}

void RunObjectPoolExamples() {
  RunObjectPoolExample1();
  RunObjectPoolExample2();
}