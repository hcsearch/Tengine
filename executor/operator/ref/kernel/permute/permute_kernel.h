/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * License); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * AS IS BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/*
 * Copyright (c) 2019, Open AI Lab
 * Author: jjzeng@openailab.com
 */

#ifndef __PERMUTE_KERNEL_H__
#define __PERMUTE_KERNEL_H__

#include <stdint.h>
#include <math.h>

#include "compiler_fp16.h"

#ifdef __cplusplus
extern "C" {
#endif

struct permute_param
{
    int order0;
    int order1;
    int order2;
    int order3;

    int in_dim[4];
    int layout;
};

typedef int (*permute_t)(const void* in_data,void* out_data,const permute_param* param) ;

#ifdef CONFIG_KERNEL_FP32
#include "permute_fp32.c"
#endif

#ifdef CONFIG_KERNEL_FP16
#include "permute_fp16.c"
#endif

#ifdef CONFIG_KERNEL_INT8
#include "permute_int8.c"
#endif

#ifdef CONFIG_KERNEL_UINT8
#include "permute_uint8.c"
#endif

#ifdef __cplusplus
}
#endif

#endif
