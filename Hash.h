/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef HASH_H_

#define HASH_H_

#include <string>
#include <vector>

namespace android {

struct Hash {
    static const Hash &getHash(const std::string &path);

    // returns matching hashes of interfaceName in $path/current.txt
    static std::vector<std::string> lookupHash(const std::string &path,
                                               const std::string &interfaceName,
                                               std::string *err);

    std::string hexString() const;

    const std::vector<uint8_t> &raw() const;
    const std::string &getPath() const;

private:
    Hash(const std::string &path);

    const std::string mPath;
    const std::vector<uint8_t> mHash;
};

}  // namespace android

#endif  // HASH_H_

