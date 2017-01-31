/*
 * H.265 video codec.
 * Copyright (c) 2013-2015 struktur AG, Joachim Bauch <bauch@struktur.de>
 *
 * This file is part of libde265.
 *
 * libde265 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * libde265 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with libde265.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "arm.h"
#include "arm-motion.h"

#include <stdio.h>

// TODO: on linux, use getauxval(AT_HWCAP);
static bool detect_neon()
{
  return true;
}


void init_acceleration_functions_neon(struct acceleration_functions* accel)
{
#ifdef HAVE_NEON
  //printf("neon\n");
#endif
}

void init_acceleration_functions_aarch64(struct acceleration_functions* accel)
{
#ifdef HAVE_AARCH64
  //printf("aarch64\n");
#endif

  accel->put_unweighted_pred_8   = put_pred_8_neon;
  accel->put_weighted_pred_avg_8 = put_bipred_8_neon;

  accel->put_hevc_qpel_8[1][0] = mc_qpel_h1_8_neon;
  accel->put_hevc_qpel_8[2][0] = mc_qpel_h2_8_neon;
  accel->put_hevc_qpel_8[3][0] = mc_qpel_h3_8_neon;

  accel->put_hevc_epel_8       = mc_noshift_8_chroma_neon;
  accel->put_hevc_qpel_8[0][0] = mc_noshift_8_luma_neon;
}
