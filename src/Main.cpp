/**
 * @file
 * @brief Source file for Main class (example app for libopenshot)
 * @author Jonathan Thomas <jonathan@openshot.org>
 *
 * @section LICENSE
 *
 * Copyright (c) 2008-2014 OpenShot Studios, LLC
 * <http://www.openshotstudios.com/>. This file is part of
 * OpenShot Library (libopenshot), an open-source project dedicated to
 * delivering high quality video editing and animation solutions to the
 * world. For more information visit <http://www.openshot.org/>.
 *
 * OpenShot Library (libopenshot) is free software: you can redistribute it
 * and/or modify it under the terms of the GNU Affero General Public License
 * as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * OpenShot Library (libopenshot) is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with OpenShot Library. If not, see <http://www.gnu.org/licenses/>.
 *
 * Also, if your software can interact with users remotely through a computer
 * network, you should also make sure that it provides a way for users to
 * get its source. For example, if your program is a web application, its
 * interface could display a "Source" link that leads users to an archive
 * of the code. There are many ways you could offer source, and different
 * solutions will be better for different programs; see section 13 for the
 * specific requirements.
 *
 * You should also get your employer (if you work as a programmer) or school,
 * if any, to sign a "copyright disclaimer" for the program, if necessary.
 * For more information on this, and how to apply and follow the GNU AGPL, see
 * <http://www.gnu.org/licenses/>.
 */

#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <tr1/memory>
#include "../include/OpenShot.h"
#include "../include/Json.h"
#include <omp.h>


using namespace openshot;
using namespace tr1;

int main(int argc, char* argv[])
{

	Timeline t1000(1280, 720, Fraction(24,1), 44100, 2);
	t1000.ApplyJsonDiff("[{\"key\": [\"clips\"], \"value\": {\"end\": 8.0, \"perspective_c1_y\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": -1.0}, \"interpolation\": 2}]}, \"perspective_c1_x\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": -1.0}, \"interpolation\": 2}]}, \"location_y\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 0.0}, \"interpolation\": 2}]}, \"location_x\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 0.0}, \"interpolation\": 2}]}, \"reader\": {\"acodec\": \"\", \"channels\": 0, \"video_length\": \"2592000\", \"video_timebase\": {\"den\": 30, \"num\": 1}, \"type\": \"ImageReader\", \"fps\": {\"den\": 1, \"num\": 30}, \"interlaced_frame\": false, \"video_bit_rate\": 0, \"display_ratio\": {\"den\": 79, \"num\": 100}, \"vcodec\": \"Portable Network Graphics\", \"audio_stream_index\": -1, \"top_field_first\": true, \"has_audio\": false, \"has_video\": true, \"sample_rate\": 0, \"file_size\": \"412980\", \"pixel_ratio\": {\"den\": 1, \"num\": 1}, \"video_stream_index\": -1, \"audio_timebase\": {\"den\": 1, \"num\": 1}, \"pixel_format\": -1, \"duration\": 86400.0, \"height\": 1975, \"path\": \"/home/jonathan/Downloads/openshot_studios_banner1.png\", \"audio_bit_rate\": 0, \"width\": 2500}, \"crop_width\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": -1.0}, \"interpolation\": 2}]}, \"gravity\": 4, \"id\": \"BMCWP7ACMR\", \"title\": \"openshot_studios_banner1.png\", \"file_id\": \"JJNH7JOX9M\", \"shear_x\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 0.0}, \"interpolation\": 2}]}, \"shear_y\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 0.0}, \"interpolation\": 2}]}, \"position\": 0.0, \"layer\": 0, \"wave_color\": {\"red\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 0.0}, \"interpolation\": 2}]}, \"green\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 28672.0}, \"interpolation\": 2}]}, \"blue\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 65280.0}, \"interpolation\": 2}]}}, \"alpha\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 0.0}, \"interpolation\": 2}]}, \"rotation\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 0.0}, \"interpolation\": 2}]}, \"waveform\": false, \"time\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 0.0}, \"interpolation\": 2}]}, \"perspective_c4_x\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": -1.0}, \"interpolation\": 2}]}, \"crop_height\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": -1.0}, \"interpolation\": 2}]}, \"perspective_c4_y\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": -1.0}, \"interpolation\": 2}]}, \"crop_x\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 0.0}, \"interpolation\": 2}]}, \"crop_y\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 0.0}, \"interpolation\": 2}]}, \"start\": 0.0, \"scale\": 1, \"perspective_c2_x\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": -1.0}, \"interpolation\": 2}]}, \"perspective_c2_y\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": -1.0}, \"interpolation\": 2}]}, \"anchor\": 0, \"image\": \"/home/jonathan/.openshot_qt/thumbnail/JJNH7JOX9M.png\", \"scale_y\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 1.0}, \"interpolation\": 2}]}, \"scale_x\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 1.0}, \"interpolation\": 2}]}, \"duration\": 86400.0, \"perspective_c3_y\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": -1.0}, \"interpolation\": 2}]}, \"perspective_c3_x\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": -1.0}, \"interpolation\": 2}]}, \"volume\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 1.0}, \"interpolation\": 2}]}}, \"partial\": false, \"type\": \"insert\"}]");
	t1000.GetFrame(0)->Display();
	t1000.ApplyJsonDiff("[{\"key\": [\"clips\", {\"id\": \"BMCWP7ACMR\"}], \"value\": {\"end\": 8, \"perspective_c1_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"perspective_c1_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"location_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"location_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"reader\": {\"acodec\": \"\", \"channels\": 0, \"video_timebase\": {\"den\": 30, \"num\": 1}, \"type\": \"ImageReader\", \"video_length\": \"2592000\", \"has_video\": true, \"video_bit_rate\": 0, \"display_ratio\": {\"den\": 79, \"num\": 100}, \"vcodec\": \"Portable Network Graphics\", \"audio_stream_index\": -1, \"top_field_first\": true, \"fps\": {\"den\": 1, \"num\": 30}, \"has_audio\": false, \"interlaced_frame\": false, \"sample_rate\": 0, \"file_size\": \"412980\", \"pixel_ratio\": {\"den\": 1, \"num\": 1}, \"video_stream_index\": -1, \"audio_timebase\": {\"den\": 1, \"num\": 1}, \"pixel_format\": -1, \"duration\": 86400, \"height\": 1975, \"path\": \"/home/jonathan/Downloads/openshot_studios_banner1.png\", \"audio_bit_rate\": 0, \"width\": 2500}, \"crop_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"crop_width\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"gravity\": 4, \"id\": \"BMCWP7ACMR\", \"scale_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 1}, \"interpolation\": 2}]}, \"shear_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"shear_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"position\": 0, \"layer\": 3, \"$$hashKey\": \"00J\", \"alpha\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"rotation\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"waveform\": false, \"time\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"crop_height\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"perspective_c4_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"perspective_c4_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"wave_color\": {\"red\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"green\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 28672}, \"interpolation\": 2}]}, \"blue\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 65280}, \"interpolation\": 2}]}}, \"crop_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"start\": 0, \"perspective_c3_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"scale\": 1, \"perspective_c2_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"perspective_c2_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"anchor\": 0, \"image\": \"/home/jonathan/.openshot_qt/thumbnail/JJNH7JOX9M.png\", \"file_id\": \"JJNH7JOX9M\", \"scale_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 1}, \"interpolation\": 2}]}, \"duration\": 86400, \"perspective_c3_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"title\": \"openshot_studios_banner1.png\", \"volume\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 1}, \"interpolation\": 2}]}}, \"partial\": false, \"type\": \"update\"}]");
	t1000.GetFrame(0)->Display();
	t1000.ApplyJsonDiff("[{\"key\": [\"clips\", {\"id\": \"BMCWP7ACMR\"}], \"value\": {\"end\": 50, \"perspective_c1_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"perspective_c1_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"location_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"location_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"reader\": {\"acodec\": \"\", \"channels\": 0, \"video_timebase\": {\"den\": 30, \"num\": 1}, \"type\": \"ImageReader\", \"video_length\": \"2592000\", \"has_video\": true, \"video_bit_rate\": 0, \"display_ratio\": {\"den\": 79, \"num\": 100}, \"vcodec\": \"Portable Network Graphics\", \"audio_stream_index\": -1, \"top_field_first\": true, \"fps\": {\"den\": 1, \"num\": 30}, \"has_audio\": false, \"interlaced_frame\": false, \"sample_rate\": 0, \"file_size\": \"412980\", \"pixel_ratio\": {\"den\": 1, \"num\": 1}, \"video_stream_index\": -1, \"audio_timebase\": {\"den\": 1, \"num\": 1}, \"pixel_format\": -1, \"duration\": 86400, \"height\": 1975, \"path\": \"/home/jonathan/Downloads/openshot_studios_banner1.png\", \"audio_bit_rate\": 0, \"width\": 2500}, \"crop_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"crop_width\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"gravity\": 4, \"id\": \"BMCWP7ACMR\", \"scale_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 1}, \"interpolation\": 2}]}, \"shear_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"shear_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"position\": 0, \"layer\": 3, \"$$hashKey\": \"00J\", \"alpha\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"rotation\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"waveform\": false, \"time\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"crop_height\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"perspective_c4_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"perspective_c4_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"wave_color\": {\"red\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"green\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 28672}, \"interpolation\": 2}]}, \"blue\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 65280}, \"interpolation\": 2}]}}, \"crop_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"start\": 0, \"perspective_c3_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"scale\": 1, \"perspective_c2_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"perspective_c2_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"anchor\": 0, \"image\": \"/home/jonathan/.openshot_qt/thumbnail/JJNH7JOX9M.png\", \"file_id\": \"JJNH7JOX9M\", \"scale_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 1}, \"interpolation\": 2}]}, \"duration\": 86400, \"perspective_c3_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"title\": \"openshot_studios_banner1.png\", \"volume\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 1}, \"interpolation\": 2}]}}, \"partial\": false, \"type\": \"update\"}]");
	t1000.GetFrame(0)->Display();
	t1000.ApplyJsonDiff("[{\"key\": [\"clips\"], \"value\": {\"end\": 8.0, \"perspective_c1_y\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": -1.0}, \"interpolation\": 2}]}, \"perspective_c1_x\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": -1.0}, \"interpolation\": 2}]}, \"location_y\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 0.0}, \"interpolation\": 2}]}, \"location_x\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 0.0}, \"interpolation\": 2}]}, \"reader\": {\"acodec\": \"\", \"channels\": 0, \"video_length\": \"2592000\", \"video_timebase\": {\"den\": 30, \"num\": 1}, \"type\": \"ImageReader\", \"fps\": {\"den\": 1, \"num\": 30}, \"interlaced_frame\": false, \"video_bit_rate\": 0, \"display_ratio\": {\"den\": 1, \"num\": 1}, \"vcodec\": \"Portable Network Graphics\", \"audio_stream_index\": -1, \"top_field_first\": true, \"has_audio\": false, \"has_video\": true, \"sample_rate\": 0, \"file_size\": \"544426\", \"pixel_ratio\": {\"den\": 1, \"num\": 1}, \"video_stream_index\": -1, \"audio_timebase\": {\"den\": 1, \"num\": 1}, \"pixel_format\": -1, \"duration\": 86400.0, \"height\": 1347, \"path\": \"/home/jonathan/Downloads/OSlogo.png\", \"audio_bit_rate\": 0, \"width\": 1347}, \"crop_width\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": -1.0}, \"interpolation\": 2}]}, \"gravity\": 4, \"id\": \"0EW6OJW1N9\", \"title\": \"OSlogo.png\", \"file_id\": \"1YD3C3IZHX\", \"shear_x\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 0.0}, \"interpolation\": 2}]}, \"shear_y\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 0.0}, \"interpolation\": 2}]}, \"position\": 0.0, \"layer\": 0, \"wave_color\": {\"red\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 0.0}, \"interpolation\": 2}]}, \"green\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 28672.0}, \"interpolation\": 2}]}, \"blue\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 65280.0}, \"interpolation\": 2}]}}, \"alpha\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 0.0}, \"interpolation\": 2}]}, \"rotation\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 0.0}, \"interpolation\": 2}]}, \"waveform\": false, \"time\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 0.0}, \"interpolation\": 2}]}, \"perspective_c4_x\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": -1.0}, \"interpolation\": 2}]}, \"crop_height\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": -1.0}, \"interpolation\": 2}]}, \"perspective_c4_y\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": -1.0}, \"interpolation\": 2}]}, \"crop_x\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 0.0}, \"interpolation\": 2}]}, \"crop_y\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 0.0}, \"interpolation\": 2}]}, \"start\": 0.0, \"scale\": 1, \"perspective_c2_x\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": -1.0}, \"interpolation\": 2}]}, \"perspective_c2_y\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": -1.0}, \"interpolation\": 2}]}, \"anchor\": 0, \"image\": \"/home/jonathan/.openshot_qt/thumbnail/1YD3C3IZHX.png\", \"scale_y\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 1.0}, \"interpolation\": 2}]}, \"scale_x\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 1.0}, \"interpolation\": 2}]}, \"duration\": 86400.0, \"perspective_c3_y\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": -1.0}, \"interpolation\": 2}]}, \"perspective_c3_x\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": -1.0}, \"interpolation\": 2}]}, \"volume\": {\"Points\": [{\"co\": {\"X\": 0.0, \"Y\": 1.0}, \"interpolation\": 2}]}}, \"partial\": false, \"type\": \"insert\"}]");
	t1000.GetFrame(0)->Display();
	t1000.ApplyJsonDiff("[{\"key\": [\"clips\", {\"id\": \"0EW6OJW1N9\"}], \"value\": {\"end\": 8, \"perspective_c1_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"perspective_c1_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"location_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"location_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"reader\": {\"acodec\": \"\", \"channels\": 0, \"video_timebase\": {\"den\": 30, \"num\": 1}, \"type\": \"ImageReader\", \"video_length\": \"2592000\", \"has_video\": true, \"video_bit_rate\": 0, \"display_ratio\": {\"den\": 1, \"num\": 1}, \"vcodec\": \"Portable Network Graphics\", \"audio_stream_index\": -1, \"top_field_first\": true, \"fps\": {\"den\": 1, \"num\": 30}, \"has_audio\": false, \"interlaced_frame\": false, \"sample_rate\": 0, \"file_size\": \"544426\", \"pixel_ratio\": {\"den\": 1, \"num\": 1}, \"video_stream_index\": -1, \"audio_timebase\": {\"den\": 1, \"num\": 1}, \"pixel_format\": -1, \"duration\": 86400, \"height\": 1347, \"path\": \"/home/jonathan/Downloads/OSlogo.png\", \"audio_bit_rate\": 0, \"width\": 1347}, \"crop_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"crop_width\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"gravity\": 4, \"id\": \"0EW6OJW1N9\", \"scale_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 1}, \"interpolation\": 2}]}, \"shear_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"shear_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"position\": 0, \"layer\": 4, \"$$hashKey\": \"00Q\", \"alpha\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"rotation\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"waveform\": false, \"time\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"crop_height\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"perspective_c4_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"perspective_c4_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"wave_color\": {\"red\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"green\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 28672}, \"interpolation\": 2}]}, \"blue\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 65280}, \"interpolation\": 2}]}}, \"crop_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"start\": 0, \"perspective_c3_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"scale\": 1, \"perspective_c2_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"perspective_c2_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"anchor\": 0, \"image\": \"/home/jonathan/.openshot_qt/thumbnail/1YD3C3IZHX.png\", \"file_id\": \"1YD3C3IZHX\", \"scale_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 1}, \"interpolation\": 2}]}, \"duration\": 86400, \"perspective_c3_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"title\": \"OSlogo.png\", \"volume\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 1}, \"interpolation\": 2}]}}, \"partial\": false, \"type\": \"update\"}]");
	t1000.GetFrame(0)->Display();
	t1000.ApplyJsonDiff("[{\"key\": [\"clips\", {\"id\": \"0EW6OJW1N9\"}], \"value\": {\"end\": 35, \"perspective_c1_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"perspective_c1_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"location_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"location_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"reader\": {\"acodec\": \"\", \"channels\": 0, \"video_timebase\": {\"den\": 30, \"num\": 1}, \"type\": \"ImageReader\", \"video_length\": \"2592000\", \"has_video\": true, \"video_bit_rate\": 0, \"display_ratio\": {\"den\": 1, \"num\": 1}, \"vcodec\": \"Portable Network Graphics\", \"audio_stream_index\": -1, \"top_field_first\": true, \"fps\": {\"den\": 1, \"num\": 30}, \"has_audio\": false, \"interlaced_frame\": false, \"sample_rate\": 0, \"file_size\": \"544426\", \"pixel_ratio\": {\"den\": 1, \"num\": 1}, \"video_stream_index\": -1, \"audio_timebase\": {\"den\": 1, \"num\": 1}, \"pixel_format\": -1, \"duration\": 86400, \"height\": 1347, \"path\": \"/home/jonathan/Downloads/OSlogo.png\", \"audio_bit_rate\": 0, \"width\": 1347}, \"crop_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"crop_width\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"gravity\": 4, \"id\": \"0EW6OJW1N9\", \"scale_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 1}, \"interpolation\": 2}]}, \"shear_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"shear_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"position\": 0, \"layer\": 4, \"$$hashKey\": \"00Q\", \"alpha\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"rotation\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"waveform\": false, \"time\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"crop_height\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"perspective_c4_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"perspective_c4_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"wave_color\": {\"red\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"green\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 28672}, \"interpolation\": 2}]}, \"blue\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 65280}, \"interpolation\": 2}]}}, \"crop_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 0}, \"interpolation\": 2}]}, \"start\": 0, \"perspective_c3_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"scale\": 1, \"perspective_c2_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"perspective_c2_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"anchor\": 0, \"image\": \"/home/jonathan/.openshot_qt/thumbnail/1YD3C3IZHX.png\", \"file_id\": \"1YD3C3IZHX\", \"scale_x\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 1}, \"interpolation\": 2}]}, \"duration\": 86400, \"perspective_c3_y\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": -1}, \"interpolation\": 2}]}, \"title\": \"OSlogo.png\", \"volume\": {\"Points\": [{\"co\": {\"X\": 0, \"Y\": 1}, \"interpolation\": 2}]}}, \"partial\": false, \"type\": \"update\"}]");
	t1000.GetFrame(0)->Display();

	/*

	FFmpegReader sinelReader("/home/jonathan/Videos/sintel_trailer-720p.mp4");
	sinelReader.Open();

	AudioReaderSource readerSource(&sinelReader, 1, 10000);
	for (int z = 0; z < 2000; z++) {
		// Get audio chunks
		int chunk_size = 750;
		juce::AudioSampleBuffer *master_buffer = new juce::AudioSampleBuffer(sinelReader.info.channels, chunk_size);
		master_buffer->clear();
		const AudioSourceChannelInfo info = {master_buffer, 0, chunk_size};

		// Get next audio block
		readerSource.getNextAudioBlock(info);

		// Delete buffer
		master_buffer->clear();
		delete master_buffer;
	}

	return 0;

	Profile p("/home/jonathan/Apps/openshot/openshot/profiles/atsc_1080p_25");
	return 0;

	Timeline t77(640, 480, Fraction(24,1), 44100, 2);
	t77.ApplyJsonDiff("[{\"type\":\"insert\",\"key\":[\"effects\",\"effect\"],\"value\":{\"end\":0,\"id\":\"e004\",\"layer\":0,\"order\":0,\"position\":0,\"start\":0,\"type\":\"Negate\"}}]");
	cout << t77.Json() << endl;
	t77.ApplyJsonDiff("[{\"type\":\"update\",\"key\":[\"effects\",\"effect\",{\"id\":\"e004\"}],\"value\":{\"order\":10.5,\"position\":11.6,\"start\":12.7}}]");
	cout << t77.Json() << endl;
	t77.ApplyJsonDiff("[{\"type\":\"delete\",\"key\":[\"effects\",\"effect\",{\"id\":\"e004\"}],\"value\":{}}]");
	cout << t77.Json() << endl;
	t77.ApplyJsonDiff("[{\"type\":\"insert\",\"key\":[\"color\"],\"value\":{\"blue\":{\"Points\":[{\"co\":{\"X\":0,\"Y\":30},\"interpolation\":2}]},\"green\":{\"Points\":[{\"co\":{\"X\":0,\"Y\":20},\"interpolation\":2}]},\"red\":{\"Points\":[{\"co\":{\"X\":0,\"Y\":10},\"interpolation\":2}]}}}]");
	cout << t77.Json() << endl;
	t77.ApplyJsonDiff("[{\"type\":\"delete\",\"key\":[\"color\"],\"value\":{}}]");
	cout << t77.Json() << endl;
	return 0;

	//FFmpegReader r2("/home/jonathan/Videos/sintel_trailer-720p.mp4");
	//r2.Open();
	//cout << r2.Json() << endl;
	//r2.SetJson("{\"acodec\":\"\",\"audio_bit_rate\":0,\"audio_stream_index\":-1,\"audio_timebase\":{\"den\":1,\"num\":1},\"channels\":0,\"display_ratio\":{\"den\":9,\"num\":16},\"duration\":10.03333377838135,\"file_size\":\"208835074\",\"fps\":{\"den\":1,\"num\":30},\"has_audio\":false,\"has_video\":true,\"height\":1080,\"interlaced_frame\":false,\"path\":\"/home/jonathan/Videos/space_undulation_hd.mov\",\"pixel_format\":13,\"pixel_ratio\":{\"den\":72,\"num\":72},\"sample_rate\":0,\"top_field_first\":false,\"type\":\"FFmpegReader\",\"vcodec\":\"mjpeg\",\"video_bit_rate\":166513021,\"video_length\":\"301\",\"video_stream_index\":0,\"video_timebase\":{\"den\":30,\"num\":1},\"width\":1920}");
	Clip c1;
	c1.SetJson("{\"alpha\":{\"Auto_Handle_Percentage\":1,\"Points\":[{\"co\":{\"X\":100,\"Y\":100,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_left\":{\"X\":100,\"Y\":50,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_right\":{\"X\":100,\"Y\":20,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_type\":0,\"interpolation\":0}]},\"anchor\":0,\"crop_height\":{\"Auto_Handle_Percentage\":1,\"Points\":[{\"co\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_left\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_right\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_type\":0,\"interpolation\":0}]},\"crop_width\":{\"Auto_Handle_Percentage\":1,\"Points\":[{\"co\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_left\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_right\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_type\":0,\"interpolation\":0}]},\"crop_x\":{\"Auto_Handle_Percentage\":1,\"Points\":[{\"co\":{\"X\":0,\"Y\":0,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_left\":{\"X\":0,\"Y\":0,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_right\":{\"X\":0,\"Y\":0,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_type\":0,\"interpolation\":0}]},\"crop_y\":{\"Auto_Handle_Percentage\":1,\"Points\":[{\"co\":{\"X\":0,\"Y\":0,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_left\":{\"X\":0,\"Y\":0,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_right\":{\"X\":0,\"Y\":0,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_type\":0,\"interpolation\":0}]},\"end\":0,\"gravity\":4,\"layer\":0,\"location_x\":{\"Auto_Handle_Percentage\":1,\"Points\":[{\"co\":{\"X\":0,\"Y\":0,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_left\":{\"X\":0,\"Y\":0,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_right\":{\"X\":0,\"Y\":0,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_type\":0,\"interpolation\":0}]},\"location_y\":{\"Auto_Handle_Percentage\":1,\"Points\":[{\"co\":{\"X\":0,\"Y\":0,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_left\":{\"X\":0,\"Y\":0,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_right\":{\"X\":0,\"Y\":0,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_type\":0,\"interpolation\":0}]},\"perspective_c1_x\":{\"Auto_Handle_Percentage\":1,\"Points\":[{\"co\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_left\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_right\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_type\":0,\"interpolation\":0}]},\"perspective_c1_y\":{\"Auto_Handle_Percentage\":1,\"Points\":[{\"co\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_left\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_right\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_type\":0,\"interpolation\":0}]},\"perspective_c2_x\":{\"Auto_Handle_Percentage\":1,\"Points\":[{\"co\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_left\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_right\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_type\":0,\"interpolation\":0}]},\"perspective_c2_y\":{\"Auto_Handle_Percentage\":1,\"Points\":[{\"co\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_left\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_right\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_type\":0,\"interpolation\":0}]},\"perspective_c3_x\":{\"Auto_Handle_Percentage\":1,\"Points\":[{\"co\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_left\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_right\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_type\":0,\"interpolation\":0}]},\"perspective_c3_y\":{\"Auto_Handle_Percentage\":1,\"Points\":[{\"co\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_left\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_right\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_type\":0,\"interpolation\":0}]},\"perspective_c4_x\":{\"Auto_Handle_Percentage\":1,\"Points\":[{\"co\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_left\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_right\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_type\":0,\"interpolation\":0}]},\"perspective_c4_y\":{\"Auto_Handle_Percentage\":1,\"Points\":[{\"co\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_left\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_right\":{\"X\":0,\"Y\":-1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_type\":0,\"interpolation\":0}]},\"position\":0,\"rotation\":{\"Auto_Handle_Percentage\":1,\"Points\":[{\"co\":{\"X\":0,\"Y\":0,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_left\":{\"X\":0,\"Y\":0,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_right\":{\"X\":0,\"Y\":0,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_type\":0,\"interpolation\":0}]},\"scale\":1,\"scale_x\":{\"Auto_Handle_Percentage\":1,\"Points\":[{\"co\":{\"X\":0,\"Y\":1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_left\":{\"X\":0,\"Y\":1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_right\":{\"X\":0,\"Y\":1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_type\":0,\"interpolation\":0}]},\"scale_y\":{\"Auto_Handle_Percentage\":1,\"Points\":[{\"co\":{\"X\":0,\"Y\":1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_left\":{\"X\":0,\"Y\":1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_right\":{\"X\":0,\"Y\":1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_type\":0,\"interpolation\":0}]},\"shear_x\":{\"Auto_Handle_Percentage\":1,\"Points\":[{\"co\":{\"X\":0,\"Y\":0,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_left\":{\"X\":0,\"Y\":0,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_right\":{\"X\":0,\"Y\":0,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_type\":0,\"interpolation\":0}]},\"shear_y\":{\"Auto_Handle_Percentage\":1,\"Points\":[{\"co\":{\"X\":0,\"Y\":0,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_left\":{\"X\":0,\"Y\":0,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_right\":{\"X\":0,\"Y\":0,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_type\":0,\"interpolation\":0}]},\"start\":0,\"time\":{\"Auto_Handle_Percentage\":1,\"Points\":[{\"co\":{\"X\":0,\"Y\":0,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_left\":{\"X\":0,\"Y\":0,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_right\":{\"X\":0,\"Y\":0,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_type\":0,\"interpolation\":0}]},\"volume\":{\"Auto_Handle_Percentage\":1,\"Points\":[{\"co\":{\"X\":0,\"Y\":1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_left\":{\"X\":0,\"Y\":1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_right\":{\"X\":0,\"Y\":1,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_type\":0,\"interpolation\":0}]},\"wave_color\":{\"blue\":{\"Auto_Handle_Percentage\":1,\"Points\":[{\"co\":{\"X\":0,\"Y\":65280,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_left\":{\"X\":0,\"Y\":65280,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_right\":{\"X\":0,\"Y\":65280,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_type\":0,\"interpolation\":0}]},\"green\":{\"Auto_Handle_Percentage\":1,\"Points\":[{\"co\":{\"X\":0,\"Y\":28672,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_left\":{\"X\":0,\"Y\":28672,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_right\":{\"X\":0,\"Y\":28672,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_type\":0,\"interpolation\":0}]},\"red\":{\"Auto_Handle_Percentage\":1,\"Points\":[{\"co\":{\"X\":0,\"Y\":0,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_left\":{\"X\":0,\"Y\":0,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_right\":{\"X\":0,\"Y\":0,\"delta\":0,\"increasing\":true,\"repeated\":{\"den\":1,\"num\":1}},\"handle_type\":0,\"interpolation\":0}]}},\"waveform\":false}");
	//c1.Reader(&r2);
	cout << c1.Json() << endl;
	//c1.Open();
	//c1.GetFrame(150)->Save("test.bmp", 1.0);
	return 0;

	*/


//	SDLPlayer p;
//	p.Reader(&r2);
//	p.Play();
//	return 0;



	// Image of interlaced frame
//	ImageReader ir("/home/jonathan/apps/libopenshot/src/examples/interlaced.png");
//	ir.Open();
//
//	// FrameMapper to de-interlace frame
//	//FrameMapper fm(&ir, Fraction(24,1), PULLDOWN_NONE);
//	//fm.DeInterlaceFrame(ir.GetFrame(1), true)->Display();
//	Deinterlace de(false);
//	de.GetFrame(ir.GetFrame(1), 1)->Display();
//
//
//	return 0;


	// Reader
	FFmpegReader r1("/home/jonathan/Videos/marina-cam_20140221_1006.ts");
	r1.Open();
	r1.DisplayInfo();
	r1.info.has_audio = false;
	//r1.enable_seek = true;

	// FrameMapper
	//FrameMapper r(&r1, Fraction(24,1), PULLDOWN_ADVANCED);
	//r.PrintMapping();

	/* WRITER ---------------- */
	FFmpegWriter w("/home/jonathan/output.mp3");

	// Set options
	//w.SetAudioOptions(true, "libvorbis", 48000, 2, 188000);
	w.SetAudioOptions(true, "libmp3lame", 44100, 1, 12800);
	w.SetVideoOptions(true, "mpeg4", Fraction(30,1), 1280, 720, Fraction(1,1), false, false, 30000000);
	//w.SetVideoOptions(true, "libmp3lame", openshot::Fraction(30,1), 720, 360, Fraction(1,1), false, false, 3000000);

	// Prepare Streams
	w.PrepareStreams();

	// Write header
	w.WriteHeader();

	// Output stream info
	w.OutputStreamInfo();

	//for (int frame = 3096; frame <= 3276; frame++)
	for (int frame = 1; frame <= 200; frame++)
	{
//		tr1::shared_ptr<Frame> f(new Frame(frame, 1280, 720, "#000000", 44100, 2));
//		if (frame % 2 == 0)
//			f->AddColor(1280, 720, "Yellow");
//		else
//			f->AddColor(1280, 720, "Black");
//
//		f->AddOverlayNumber(f->number);
//		cout << f->number << endl;
//		w.WriteFrame(f);

		tr1::shared_ptr<Frame> f = r1.GetFrame(frame);
		if (f)
		{
			//if (frame >= 250)
			//	f->DisplayWaveform();
			//f->AddOverlayNumber(frame);
			//f->Display();

			// Write frame
			//f->Display();
			cout << "queue frame " << frame << " (" << f->number << ", " << f << ")" << endl;
			w.WriteFrame(f);
		}
	}

	// Write Footer
	w.WriteTrailer();

	// Close writer & reader
	w.Close();

	// Close timeline
	r1.Close();
	/* ---------------- */


	cout << "Successfully Finished Timeline DEMO" << endl;
	return 0;

}

