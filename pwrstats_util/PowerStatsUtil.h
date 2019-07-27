/*
 * Copyright (C) 2019 The Android Open Source Project
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
#ifndef POWERSTATSUTIL_H
#define POWERSTATSUTIL_H

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

/**
 * Classes that implement this interface can be used to provide stats in the form of key/value
 * pairs to PwrStatsUtil.
 **/
class IPwrStatsUtilDataProvider {
  public:
    virtual ~IPwrStatsUtilDataProvider() = default;
    virtual int get(std::unordered_map<std::string, uint64_t>& data) = 0;
};

/**
 * This class is used to return stats in the form of key/value pairs for all registered classes
 * that implement IPwrStatsUtilDataProvider.
 **/
class PowerStatsUtil {
  public:
    PowerStatsUtil();
    int getData(std::unordered_map<std::string, uint64_t>& data);

  private:
    std::vector<std::unique_ptr<IPwrStatsUtilDataProvider>> mDataProviders;
};

#endif  // POWERSTATSUTIL_H
