/*
 * Copyright (c) 2018-2019 Atmosphère-NX
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

static constexpr size_t SplashScreenX = {0};
static constexpr size_t SplashScreenY = {1};
static constexpr size_t SplashScreenW = {2};
static constexpr size_t SplashScreenH = {3};

static constexpr u32 SplashScreen[] = {4};
static_assert(sizeof(SplashScreen) == sizeof(u32) * SplashScreenW * SplashScreenH, "Incorrect SplashScreen definition!");