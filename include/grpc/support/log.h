/*
 *
 * Copyright 2015 gRPC authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef GRPC_SUPPORT_LOG_H
#define GRPC_SUPPORT_LOG_H

#include <stdarg.h>
#include <stdlib.h> /* for abort() */

#include "absl/base/attributes.h"

#include <grpc/support/port_platform.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Deprecated */
typedef enum gpr_log_severity {
  GPR_LOG_SEVERITY_DEBUG,
  GPR_LOG_SEVERITY_INFO,
  GPR_LOG_SEVERITY_ERROR
} gpr_log_severity;

/** Deprecated **/
#define GPR_DEBUG __FILE__, __LINE__, GPR_LOG_SEVERITY_DEBUG
#define GPR_INFO __FILE__, __LINE__, GPR_LOG_SEVERITY_INFO
#define GPR_ERROR __FILE__, __LINE__, GPR_LOG_SEVERITY_ERROR

/* Deprecated. Use absl LOG, ABSL_LOG, VLOG or ABSL_VLOG instead. */
GPRAPI void gpr_log(const char* file, int line, gpr_log_severity severity,
                    const char* format, ...) GPR_PRINT_FORMAT_CHECK(4, 5);

GPRAPI int gpr_should_log(gpr_log_severity severity);

GPRAPI void gpr_log_verbosity_init(void);

#ifdef __cplusplus
}
#endif

#endif /* GRPC_SUPPORT_LOG_H */
