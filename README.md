# crypro-Dll
crypro++ Dll demo


Need to compile crypto++ lib with dll and add codes to pch.h below:

``` c++
#define CRYPTOPP_ENABLE_COMPLIANCE_WITH_FIPS_140_2 0
#if CRYPTOPP_ENABLE_COMPLIANCE_WITH_FIPS_140_2 == 1
#pragma message("FIPS Compliance is Enabled")
#elif CRYPTOPP_ENABLE_COMPLIANCE_WITH_FIPS_140_2 == 0
#pragma message("FIPS Compliance is Disabled")
#else
#pragma message("FIPS Compliance is Ambiguous")
#endif
```

after compile cryptopp.dll successfully, this program can sccessfully compile.
