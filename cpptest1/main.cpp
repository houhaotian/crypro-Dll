#include <iostream>
#include <vector>
#include <algorithm>


#include "dll.h"
#include "cryptlib.h"
#include "filters.h"
#include "pkcspad.h"

#include <aes.h>  
#include <Hex.h>      // StreamTransformationFilter  
#include <string>  
#include <modes.h>

using namespace std;
using namespace CryptoPP;

int main()
{
   /* cout << "key length: " << AES::DEFAULT_KEYLENGTH << endl;
    cout << "key length (min): " << AES::MIN_KEYLENGTH << endl;
    cout << "key length (max): " << AES::MAX_KEYLENGTH << endl;
    cout << "block size: " << AES::BLOCKSIZE << endl;*/

    AutoSeededRandomPool rnd;

    // Generate a random key
    SecByteBlock key(0x00, AES::DEFAULT_KEYLENGTH);
    rnd.GenerateBlock(key, key.size());

    // Generate a random IV
    SecByteBlock iv(AES::BLOCKSIZE);
    rnd.GenerateBlock(iv, iv.size());

    byte plainText[] = "Hello! How are you.";
    size_t messageLen = std::strlen((char*)plainText) + 1;

    //////////////////////////////////////////////////////////////////////////
    // Encrypt

    CFB_Mode<AES>::Encryption cfbEncryption(key, key.size(), iv);
    cfbEncryption.ProcessData(plainText, plainText, messageLen);

    cout << plainText << endl;
    //////////////////////////////////////////////////////////////////////////
    // Decrypt

    CFB_Mode<AES>::Decryption cfbDecryption(key, key.size(), iv);
    cfbDecryption.ProcessData(plainText, plainText, messageLen);

    cout << plainText << endl;
    return 0;
}
