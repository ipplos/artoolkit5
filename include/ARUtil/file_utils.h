/*
 *  file_utils.h
 *  ARToolKit5
 *
 *  This file is part of ARToolKit.
 *
 *  ARToolKit is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  ARToolKit is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with ARToolKit.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  As a special exception, the copyright holders of this library give you
 *  permission to link this library with independent modules to produce an
 *  executable, regardless of the license terms of these independent modules, and to
 *  copy and distribute the resulting executable under terms of your choice,
 *  provided that you also meet, for each linked independent module, the terms and
 *  conditions of the license of that module. An independent module is a module
 *  which is neither derived from nor based on this library. If you modify this
 *  library, you may extend this exception to your version of the library, but you
 *  are not obligated to do so. If you do not wish to do so, delete this exception
 *  statement from your version.
 *
 *  Copyright 2015-2016 Daqri, LLC.
 *  Copyright 2013-2015 Daqri, LLC.
 *
 *  Author(s): Philip Lamb, Dan Bell
 *
 */

#include <stdbool.h>
#include <termios.h>
#include <stdio.h>
#ifndef __ARUtil_file_utils_h__
#define __ARUtil_file_utils_h__

#ifdef __cplusplus
extern "C" {
#endif

// Test for existence of regular file like 'test -f [dir/]file'.
// Returns 1 if file exists, 0 if not, or -1 in case of error and the error code in 'errno'.
int test_f(const char *file, const char *dir);

// Test for existence of directory like 'test -d dir'.
// Returns 1 if dir exists, 0 if not, or -1 in case of error and the error code in 'errno'.
int test_d(const char *dir);

// Copy a single file (with overwriting in case of target file already existing) like 'cp -f source_file target_file'.
// Returns 0 for success, -1 in case of error and the error code in 'errno'.
int cp_f(const char *source_file, const char *target_file);

// Make directory like 'mkdir -p path'.
// Returns 0 for success, -1 in case of error and the error code in 'errno'.
int mkdir_p(const char *path);

// Remove path like 'rm -rf path'.
// Returns 0 for success, -1 in case of error and the error code in 'errno'.
int rm_rf(const char *path);

// Rename path like 'rn path newPath'.
// Returns 0 for success, -1 in case of error and the error code in 'errno'.
int rn_f(const char *source_file, const char *target_file);
    
// Unzip a zip file like 'unzip -o zipPathname -d outPath'.
// Returns 0 in case of success, or error code < 0 in case of error (see unzip.h). If error code is -1, the error code is in 'errno'.
int unzip_od(const char *zipPathname, const char *outPath);

// Zip a zip file like 'zip zipPathname -d fileNames'.
// Returns 0 in case of success, or error code < 0 in case of error (see zip.h). If error code is -1, the error code is in 'errno'.
int zip_od(char *zipPathname, const char *baseFilePath, const char **fileNames, int totalFiles);

float get_file_size(const char * pathName);

// Read a single character from the terminal without echo, like 'read -s -n 1'.
char read_sn1(void);

#ifdef __cplusplus
}
#endif
#endif // !__ARUtil_file_utils_h__
