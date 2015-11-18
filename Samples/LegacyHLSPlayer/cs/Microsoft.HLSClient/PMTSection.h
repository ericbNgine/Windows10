/*********************************************************************************************************************
Microsft HLS SDK for Windows

Copyright (c) Microsoft Corporation

All rights reserved.

MIT License

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation
files (the ""Software""), to deal in the Software without restriction, including without limitation the rights to use, copy,
modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software
is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED *AS IS*, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

***********************************************************************************************************************/

#pragma once
#include <map>
#include <wtypes.h>
#include "BitOp.h"

namespace Microsoft {
  namespace HLSClient {
    namespace Private {

      class PMTSection
      {
      public:
        unsigned short CurrentSectionNumber;
        unsigned short MaxSectionNumber;
        std::map<unsigned short, BYTE> MapData;
        bool HasPCR;
        unsigned int PCRPID;
        PMTSection();
        ~PMTSection();
        static bool IsPMTSection(const BYTE *pesdata);
        static std::shared_ptr<PMTSection> Parse(const BYTE *pesdata);
        static bool IsHLSTimedMetadata(const BYTE * es_info_loop, unsigned int length);
      };

    }
  }
} 