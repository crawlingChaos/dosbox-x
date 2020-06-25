/*
 *  Hq2x scaler pixel shader version support code by Mitja Gros (Mitja.Gros@gmail.com)
 *
 *  OpenGL-HQ rendering code Copyright (C) 2004-2005 Jorg Walter <jwalt@garni.ch>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef __HQ2X_DIRECT3D_H_
#define __HQ2X_DIRECT3D_H_

#include "config.h"
#include <math.h>

#if C_D3DSHADERS

#define HQ2X_RESOLUTION 16

void BuildHq2xLookupTexture(Bitu width, Bitu height, Bitu rwidth, Bitu rheight, Bit8u* texture);

#define HQ2X_D3D_TABLE_DATA { \
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x24,0x24,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x6c,0x93,0x94,0x91,0x24,0x24,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x6c,0x6c,0x94,0x91,0x6e,0x4c,0x90,0x91,0x6c,0x6c,0x94,0x91,0x24,0x24,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x6c,0x6c,0x94,0x91,0x6e,0x4c,0x90,0x91,0x6c,0x6c,0x94,0x91,0x24,0x24,\
0x90,0x91,0x92,0x04,0x94,0x91,0x92,0x04,0x90,0x91,0x6c,0x93,0x94,0x91,0x96,0x97,\
0x90,0x91,0x92,0x04,0x94,0x91,0x92,0x04,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x04,0x94,0x91,0x92,0x04,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x04,0x94,0x91,0x92,0x04,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0xec,0xec,0x94,0x91,0xec,0xec,0x90,0x91,0xec,0xec,0x94,0x91,0xec,0xec,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x6c,0x4c,0x94,0x91,0x6e,0x4c,0x90,0x91,0x6c,0x6c,0x94,0x91,0x6e,0x6c,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x6c,0x4c,0x94,0x91,0x6e,0x4c,0x90,0x91,0x6c,0x6c,0x94,0x91,0x92,0x6c,\
0x90,0x91,0x92,0x04,0x94,0x91,0x92,0x04,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x4c,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x04,0x94,0x91,0x92,0x04,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x4c,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0xe8,0x92,0xe8,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0xe8,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x68,0x92,0x93,0x94,0xe8,0x92,0xe8,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0xe8,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0xe8,0x92,0xe8,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x4c,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0xe8,0x92,0xe8,\
0x90,0x91,0x92,0x4c,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0xe8,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x6c,0x90,0x91,0x6c,0x93,0x94,0xe8,0x92,0xe8,\
0x90,0x91,0x6c,0x6c,0x94,0x91,0x6c,0x4c,0x90,0x91,0x6c,0x93,0x94,0xe8,0x6c,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x6c,0x90,0x91,0x6c,0x93,0x94,0xe8,0x92,0xe8,\
0x90,0x91,0x6c,0x6c,0x94,0x91,0x6e,0x4c,0x90,0x91,0x6c,0x93,0x94,0xe8,0x24,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x6c,0x90,0x91,0x6c,0x93,0x94,0xe8,0x92,0xe8,\
0x90,0x91,0x92,0x93,0x94,0x91,0x6c,0x04,0x90,0x91,0x92,0x93,0x94,0x91,0x6c,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x6c,0x93,0x94,0xe8,0x92,0xe8,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x04,0x90,0x91,0x92,0x93,0x94,0xe8,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x48,0x48,0x48,0x48,0x48,0x48,0x48,0x4c,0x48,0x48,0x48,0x93,0x48,0x48,0x48,0x97,\
0x90,0x20,0x92,0x20,0x94,0x20,0x92,0x20,0x90,0x20,0x92,0x20,0x94,0x20,0x92,0x20,\
0x90,0x20,0xec,0xec,0x94,0x20,0xec,0xec,0x90,0x20,0xec,0x93,0x94,0x20,0xec,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x48,0x48,0x48,0x48,0x48,0x48,0x48,0x4c,0x48,0x91,0x48,0x93,0x48,0x48,0x48,0x97,\
0x90,0x20,0x92,0x93,0x94,0x20,0x92,0x4c,0x90,0x20,0x92,0x20,0x94,0x20,0x92,0x20,\
0x90,0x20,0x92,0x20,0x94,0x20,0x92,0x4c,0x90,0x20,0x92,0x93,0x94,0x20,0x92,0x4c,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x48,0x48,0x6c,0x6c,0x48,0x48,0x6c,0x4c,0x48,0x48,0x6c,0x93,0x48,0x48,0x6c,0x97,\
0x90,0x20,0x92,0x20,0x94,0x20,0x92,0x20,0x90,0x20,0x6c,0x20,0x94,0x20,0x92,0x20,\
0x90,0x20,0x6c,0x20,0x94,0x20,0x6e,0x20,0x90,0x20,0x6c,0x93,0x94,0x20,0x6e,0x4c,\
0x90,0x91,0x92,0x04,0x94,0x91,0x92,0x04,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x48,0x48,0x48,0x04,0x48,0x48,0x6c,0x04,0x48,0x68,0x48,0x93,0x48,0xec,0x6c,0x4c,\
0x90,0x20,0x92,0x93,0x94,0x20,0x92,0x04,0x90,0x20,0x6c,0x20,0x94,0x20,0x92,0x20,\
0x90,0x20,0x92,0x04,0x94,0x20,0x92,0x04,0x90,0x20,0x92,0x93,0x94,0x20,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x24,0x24,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x4c,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x24,0x24,\
0x90,0x91,0x92,0x4c,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x4c,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x6c,0x6c,0x94,0x91,0x6e,0x4c,0x90,0x91,0x6c,0x6c,0x94,0x91,0x24,0x24,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x6c,0x68,0x94,0x91,0x6e,0x4c,0x90,0x91,0x6c,0x6c,0x94,0x91,0x24,0x24,\
0x90,0x91,0x92,0x04,0x94,0x91,0x92,0x04,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x04,0x94,0x91,0x92,0x04,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x04,0x94,0x91,0x92,0x04,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x04,0x94,0x91,0x92,0x04,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0xec,0x93,0x94,0x91,0xec,0x4c,0x90,0x91,0xec,0xec,0x94,0x91,0xec,0xec,\
0x90,0x91,0x92,0x4c,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x4c,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x6c,0x4c,0x94,0x91,0x6e,0x4c,0x90,0x91,0x6c,0x6c,0x94,0x91,0x6e,0x6c,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x6c,0x93,0x94,0x91,0x6e,0x4c,0x90,0x91,0x6c,0x68,0x94,0x91,0x6e,0x6c,\
0x90,0x91,0x92,0x04,0x94,0x91,0x92,0x04,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x4c,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x04,0x94,0x91,0x92,0x04,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x04,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x97,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x4c,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x4c,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x4c,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x6c,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x6c,0x6c,0x94,0x91,0x6c,0x4c,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x6c,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x6c,0x6c,0x94,0x91,0x6e,0x4c,0x90,0x91,0x6c,0x93,0x94,0x91,0x24,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x04,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x6c,0x04,0x90,0x91,0x92,0x93,0x94,0x91,0x6c,0x97,\
0x90,0x91,0x92,0x4c,0x94,0x91,0x92,0x04,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x04,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x48,0x48,0x48,0x48,0x48,0x48,0x48,0x4c,0x48,0x48,0x92,0x93,0x48,0x48,0x48,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0xec,0xec,0x94,0x91,0xec,0x4c,0x90,0x91,0xec,0x93,0x94,0x91,0xec,0x4c,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x48,0x48,0x48,0x4c,0x48,0x48,0x48,0x4c,0x48,0x48,0x48,0x93,0x48,0x48,0x48,0x97,\
0x90,0x91,0x92,0x4c,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x4c,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x48,0x48,0x6c,0x6c,0x48,0x48,0x6c,0x4c,0x48,0x48,0x6c,0x93,0x48,0x48,0x96,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x6c,0x6c,0x94,0x91,0x6e,0x4c,0x90,0x91,0x6c,0x93,0x94,0x91,0x6e,0x97,\
0x90,0x91,0x92,0x04,0x94,0x91,0x92,0x04,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x48,0x48,0x48,0x04,0x48,0x48,0x6c,0x04,0x48,0x48,0x48,0x93,0x48,0x48,0x6c,0x97,\
0x90,0x91,0x92,0x04,0x94,0x91,0x92,0x04,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x04,0x94,0x91,0x92,0x04,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x6c,0x90,0x68,0x92,0x93,0x94,0x91,0x24,0x24,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x6c,0x90,0x68,0x92,0x93,0x94,0x91,0x24,0x24,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x6c,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x6c,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,0x90,0x68,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x6c,0x6c,0x94,0x91,0x6e,0x6c,0x90,0x68,0x6c,0x6c,0x94,0x91,0x24,0x24,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,0x90,0x68,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x6c,0x6c,0x94,0x91,0x6e,0x6c,0x90,0x68,0x6c,0x6c,0x94,0x91,0x24,0x24,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,0x90,0x68,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x6c,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,0x90,0x68,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x6c,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0xec,0xec,0x94,0x91,0xec,0xec,0x90,0x68,0xec,0xec,0x94,0x91,0xec,0xec,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,0x90,0x68,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x6c,0x6c,0x94,0x91,0x6e,0x6c,0x90,0x68,0x6c,0x6c,0x94,0x91,0x6e,0x6c,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,0x90,0x68,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x6c,0x6c,0x94,0x91,0x6e,0x6c,0x90,0x68,0x6c,0x6c,0x94,0x91,0x6e,0x6c,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,0x90,0x68,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,0x90,0x68,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x68,0x92,0x68,0x94,0x69,0x92,0x4c,0x90,0x68,0x92,0x68,0x94,0xe8,0x92,0xe8,\
0x90,0x68,0x92,0x68,0x94,0x6c,0x92,0x4c,0x90,0x68,0x92,0x93,0x94,0x6c,0x24,0x97,\
0x90,0x68,0x92,0x68,0x94,0x69,0x92,0x4c,0x90,0x68,0x92,0x68,0x94,0xe8,0x92,0xe8,\
0x90,0x68,0x92,0x68,0x94,0x69,0x92,0x4c,0x90,0x68,0x92,0x93,0x94,0xe8,0x24,0x97,\
0x90,0x68,0x92,0x68,0x94,0x69,0x92,0x4c,0x90,0x68,0x92,0x68,0x94,0xe8,0x92,0xe8,\
0x90,0x68,0x92,0x68,0x94,0x6c,0x92,0x4c,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x68,0x92,0x6c,0x94,0x69,0x92,0x4c,0x90,0x68,0x92,0x68,0x94,0xe8,0x92,0xe8,\
0x90,0x68,0x92,0x68,0x94,0x69,0x92,0x4c,0x90,0x68,0x92,0x93,0x94,0xe8,0x92,0x97,\
0x90,0x68,0x92,0x68,0x94,0x69,0x92,0x6c,0x90,0x68,0x6c,0x68,0x94,0xe8,0x92,0xe8,\
0x90,0x68,0x6c,0x90,0x94,0x69,0x6e,0x6c,0x90,0x68,0x6c,0x93,0x94,0xe8,0x24,0x97,\
0x90,0x68,0x92,0x68,0x94,0x69,0x92,0x6c,0x90,0x68,0x6c,0x68,0x94,0xe8,0x92,0xe8,\
0x90,0x68,0x6c,0x6c,0x94,0x69,0x6e,0x6c,0x90,0x68,0x6c,0x93,0x94,0xe8,0x24,0x97,\
0x90,0x68,0x92,0x68,0x94,0x69,0x92,0x6c,0x90,0x68,0x6c,0x68,0x94,0xe8,0x92,0xe8,\
0x90,0x68,0x92,0x68,0x94,0x69,0x92,0x68,0x90,0x68,0x92,0x90,0x94,0xe8,0x92,0x97,\
0x90,0x68,0x92,0x68,0x94,0x69,0x92,0x97,0x90,0x68,0x6c,0x68,0x94,0xe8,0x92,0xe8,\
0x90,0x68,0x92,0x90,0x94,0x69,0x92,0x68,0x90,0x68,0x92,0x93,0x94,0xe8,0x92,0x97,\
0x90,0x68,0x92,0x4c,0x94,0x69,0x92,0x4c,0x90,0x68,0x92,0x68,0x94,0x69,0x92,0x68,\
0x48,0x68,0x48,0x68,0x48,0x6c,0x48,0x4c,0x48,0x68,0x48,0x93,0x48,0x6c,0x48,0x97,\
0x90,0x68,0x92,0x4c,0x94,0x69,0x92,0x4c,0x90,0x68,0x92,0x68,0x94,0x91,0x92,0x68,\
0x90,0x68,0xec,0xec,0x94,0x69,0xec,0xec,0x90,0x68,0xec,0x93,0x94,0x69,0xec,0x4c,\
0x90,0x68,0x92,0x4c,0x94,0x69,0x92,0x4c,0x90,0x68,0x92,0x68,0x94,0x69,0x92,0x68,\
0x48,0x68,0x48,0x68,0x48,0x6c,0x48,0x4c,0x48,0x68,0x48,0x93,0x48,0x95,0x48,0x97,\
0x90,0x68,0x92,0x93,0x94,0x69,0x92,0x4c,0x90,0x68,0x92,0x6c,0x94,0x69,0x92,0x68,\
0x90,0x68,0x92,0x68,0x94,0x69,0x92,0x4c,0x90,0x68,0x92,0x93,0x94,0x69,0x92,0x97,\
0x90,0x68,0x92,0x68,0x94,0x69,0x92,0x68,0x90,0x68,0x6c,0x68,0x94,0x69,0x92,0x68,\
0x48,0x68,0x6c,0x6c,0x48,0x69,0x6e,0x90,0x48,0x68,0x6c,0x93,0x48,0x69,0x6e,0x97,\
0x90,0x68,0x92,0x68,0x94,0x69,0x92,0x68,0x90,0x68,0x6c,0x68,0x94,0x69,0x92,0x68,\
0x90,0x68,0x6c,0x6c,0x94,0x69,0x6e,0x6c,0x90,0x68,0x6c,0x93,0x94,0x69,0x6e,0x97,\
0x90,0x68,0x92,0x68,0x94,0x69,0x92,0x68,0x90,0x68,0x6c,0x68,0x94,0x69,0x92,0x68,\
0x48,0x68,0x48,0x68,0x48,0x69,0x48,0x68,0x48,0x68,0x48,0x93,0x48,0x91,0x48,0x97,\
0x90,0x68,0x92,0x20,0x94,0x69,0x92,0x93,0x90,0x68,0x6c,0x20,0x94,0x69,0x92,0x68,\
0x90,0x68,0x92,0x68,0x94,0x69,0x92,0x68,0x90,0x68,0x92,0x93,0x94,0x69,0x92,0x97,\
0x90,0x91,0x92,0xcc,0x94,0x91,0x92,0xcc,0x90,0x68,0x92,0x93,0x94,0x95,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x6c,0x90,0x68,0x92,0x93,0x94,0x91,0x24,0x24,\
0x90,0x91,0x92,0xcc,0x94,0x91,0x92,0xcc,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x4c,0x90,0x68,0x92,0x93,0x94,0x91,0x24,0x24,\
0x90,0x91,0x92,0xcc,0x94,0x91,0x92,0xcc,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0xcc,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0xcc,0x94,0x91,0x92,0xcc,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x4c,0x94,0x91,0x92,0xcc,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,0x90,0x68,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x6c,0x6c,0x94,0x91,0x6e,0x6c,0x90,0x68,0x6c,0x6c,0x94,0x91,0x24,0x24,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,0x90,0x68,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x6c,0x6c,0x94,0x91,0x6e,0x97,0x90,0x68,0x6c,0x6c,0x94,0x91,0x24,0x24,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,0x90,0x68,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,0x90,0x68,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0xcc,0x94,0x91,0x92,0xcc,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0xcc,0x94,0x91,0x92,0xcc,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0xcc,0x94,0x91,0x92,0xcc,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0xec,0x93,0x94,0x91,0xec,0xcc,0x90,0x68,0xec,0xec,0x94,0x91,0xec,0xec,\
0x90,0x91,0x92,0xcc,0x94,0x91,0x92,0xcc,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0xcc,0x94,0x91,0x92,0xcc,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0xcc,0x94,0x91,0x92,0xcc,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0xcc,0x94,0x91,0x92,0xcc,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,0x90,0x68,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x6c,0x6c,0x94,0x91,0x6e,0x6c,0x90,0x68,0x6c,0x6c,0x94,0x91,0x6e,0x6c,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,0x90,0x68,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x6c,0xec,0x94,0x91,0x6e,0x93,0x90,0x68,0x6c,0xec,0x94,0x91,0x6e,0x6c,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,0x90,0x68,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,0x90,0x68,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0xec,0x94,0x91,0x92,0xcc,0x90,0x68,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0xcc,0x94,0x91,0x92,0xcc,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x6c,0x92,0xcc,0x90,0x91,0x92,0x93,0x94,0x6c,0x92,0x97,\
0x90,0x91,0x92,0xcc,0x94,0x91,0x92,0xcc,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0xcc,0x90,0x91,0x92,0x93,0x94,0x91,0x24,0x97,\
0x90,0x91,0x92,0xcc,0x94,0x91,0x92,0xcc,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x6c,0x92,0xcc,0x90,0x91,0x92,0x93,0x94,0x6c,0x92,0x97,\
0x90,0x91,0x92,0xcc,0x94,0x91,0x92,0xcc,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0xcc,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x6c,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x6c,0x6c,0x94,0x91,0x6e,0x6c,0x90,0x91,0x6c,0x90,0x94,0x91,0x24,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x6c,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x6c,0x90,0x94,0x91,0x6e,0x6c,0x90,0x91,0x6c,0x93,0x94,0x91,0x24,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x90,0x94,0x91,0x92,0x97,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x4c,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x48,0x48,0x48,0xcc,0x48,0x6c,0x48,0xcc,0x48,0x48,0x6c,0x93,0x48,0x6c,0x14,0x4c,\
0x90,0x91,0x92,0x4c,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0xec,0xcc,0x94,0x91,0xec,0xcc,0x90,0x91,0xec,0x93,0x94,0x91,0xec,0x97,\
0x90,0x91,0x92,0x4c,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x48,0x48,0x48,0xcc,0x48,0x6c,0x48,0xcc,0x48,0x48,0x48,0x93,0x48,0x6c,0x48,0x97,\
0x90,0x91,0x92,0xcc,0x94,0x91,0x92,0x4c,0x90,0x91,0x92,0x97,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0xcc,0x94,0x91,0x92,0xcc,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x48,0x48,0x6c,0x6c,0x48,0x48,0x6e,0x6c,0x48,0x48,0x6c,0x93,0x48,0x48,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x6c,0x6c,0x94,0x91,0x6e,0x6c,0x90,0x91,0x6c,0x93,0x94,0x91,0x6e,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x48,0x48,0x48,0x97,0x48,0x48,0x48,0x97,0x48,0x48,0x48,0x93,0x48,0x48,0x48,0x97,\
0x90,0x91,0x92,0x20,0x94,0x91,0x92,0x04,0x90,0x91,0x6c,0x93,0x94,0x91,0x92,0x97,\
0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,0x90,0x91,0x92,0x93,0x94,0x91,0x92,0x97,\
}

#endif // C_D3DSHADERS

#endif // __HQ2X_DIRECT3D_H_
