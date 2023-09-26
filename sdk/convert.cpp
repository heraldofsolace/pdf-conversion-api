#include <iostream>
#include <locale>
#include <codecvt>
#include <string>
#include <cstdlib>
#include <stdlib.h>

#include "common/fs_common.h"
#include "addon/conversion/fs_convert.h"
using namespace std;
using namespace foxit;
using namespace common;
using namespace pdf;
using namespace foxit::common;
using namespace foxit::addon::conversion;

int main(int argc, char *argv[])
{
    // The value of "sn" can be got from "gsdk_sn.txt" (the string after "SN=").
    const char *sn = std::getenv("Omr84v9s5ifPDvpub930F5JPSdJJahBQ1d5igqooY1Sb3zyXGtYXxA==");
    // The value of "key" can be got from "gsdk_key.txt" (the string after "Sign=").
    const char *key = std::getenv("8f3gFUOMvWsN+XetmKjesLptEYT1ig6PK1CEz2o0DW4tZ6/exCmG5GPGgzhkBbuEpb4RGJAqjEuPZbl5VIecCfz79/u18jbeUNsMWI/9txygNhP1uzlM+I9s8ixNedL+i1DSHAZpOYD9KICJ/iGQVpKjMiybu9KwN++f2lABPbGXeLQ7oeK1X15Kxo2QVwCCL7nR2qs3J3tmSj+CiHhjVkqusgu4I1qiM9Y+cWFSK7evBQ9BtyeXGhdhk2ry1FVtESMk2Dlval1pEldGzqg6e9jY70JKX23CMVqLCMeOqK3fbC/Vvzac2ML+D0LCPcCiUPlJQ3zPbI4fjAWmYhvQbt8WDGL6k33nvijVr0V6qiAbdq02ePaXMFAyGEpNzi3Am8UQW6aNglM9BUg9xPMh8af9R/1T4+3Wqk+WdlGopetayGPA1xMwjdHaKWGp2ZFY6EC+2nnTxmE7p2uis0kQTLyHaHgXv0cFeG4vawsXcFf6b7gh3qXOFVx1mVouQEK332IGuTduRmDj/Oj1/LmKMyx8xpx7zkddUx93khVbx40Vr4AAKZVxa2owvzf/+NBtx6w0BqHoI67U217JogmwhrQLkuv9U37kznY7/RmDL8WlD9IdIdqzjR+fVFjZwin5/bKklrqmqRv7JNRqB5JWRcmUWKouXwFKSbtMQjv6PD8dP5yIXcLTXuW66uHwLOdxqwqx+DkxzykXWKPGPyRvm6k5MZf1r8uOYZK6nLxnFKoKv/SpCaiCjH6koc/XAhJaBwk1tXBxzugrdxhyYNNlG1TwC6YKhMqL9HP8ArqbTZiMCyVayBtzlt4nH5SLO/Km3H72GABSOZ2ws6q8SppYoqMR0H5d8kXdI56twidchmw55Ae/+AiGLsCQCZ65BaeNkpm4T1XJe6s/bVFMyQQ1b7ywWZoF4jCmpCTy/tLKQI7vPEt2WSD9M9A3ry8B/zPYojXjOoKcWcQVZbjAwe220vov4QWBIWU6IQC6yunWJQaxMb1nJUl/iZWpbbYLxwxRK7nFhLfW1H7LRSG1vn4vogKcSzEiy79JTVpl1DU9EqrG5tAT+JCWtMdwdDfZYG+s/nE4ca7Ve9a9TBwEVNG0rIYHFxqGBrtiJy06dcPuEnygLt0los9XliR862eOt8EcH/79thsqhQwa+U4omt8POIKZZ1Dz8tNXAWQKu4gbH6iGJszeutuXjiix22/kVOf7Fx+G0G9tHZ25Fre/qNqIkboJ99FKswzB9/G6ob/ZULBFNqLWmpM1DvVIhMK3O99oSMfvvbSktakHMBvazWONljKCDfUuZhFPyJs2dg8l6ym6EU/ixqxjD66ksJhLR1pL2IzIpYC7599jsBN84r45vGyjPsOyjWnaiM1MXQ==");

    // Initialize the library before using it
    foxit::ErrorCode code = Library::Initialize(sn, key);
    if (code != foxit::e_ErrSuccess)
    {
        return FALSE;
    }

    // Get the parameters for the conversion
    Word2PDFSettingData word2PdfSettingData;
    // The first positional command line parameter contains the DOCX file path
    WString doc;
    doc.ConvertFrom(argv[1]);
    // The second positional command line parameter contains the PDF file's desired path
    WString pdf;          
    pdf.ConvertFrom(argv[2]);

    // Convert the document
    Convert::FromWord(doc, L"", pdf, L"/opt/libreoffice6.4/program", word2PdfSettingData);

    // Release the library when finished
    Library::Release();

    // Exit with 0 to signify everything executed successfully.
    exit(0);
}
