// Generated by kleverkeys-generator

#include "KleverKeys.h"
#include "easy_encrypt/EasyEncrypt.h"

//1D219FDD0F2F65E64DCE4D51F4513E5EC7874FE3CD1026CC9552EA5FDBC6960C
DEFINE_HIDDEN_STRING(String1, 0x47, ('1')('D')('2')('1')('9')('F')('D')('D')('0')('F')('2')('F')('6')('5')('E')('6')('4')('D')('C')('E')('4')('D')('5')('1')('F')('4')('5')('1')('3')('E')('5')('E')('C')('7')('8')('7')('4')('F')('E')('3')('C')('D')('1')('0')('2')('6')('C')('C')('9')('5')('5')('2')('E')('A')('5')('F')('D')('B')('C')('6')('9')('6')('0')('C'))
//6D4FA378EF3D6F3E66BD0E9F8C1DF7A026C89E091ED90B326BE8D5AEA6B6CAAE
DEFINE_HIDDEN_STRING(String2, 0x04, ('6')('D')('4')('F')('A')('3')('7')('8')('E')('F')('3')('D')('6')('F')('3')('E')('6')('6')('B')('D')('0')('E')('9')('F')('8')('C')('1')('D')('F')('7')('A')('0')('2')('6')('C')('8')('9')('E')('0')('9')('1')('E')('D')('9')('0')('B')('3')('2')('6')('B')('E')('8')('D')('5')('A')('E')('A')('6')('B')('6')('C')('A')('A')('E'))
//EA41802E7116F9EBE67E5FF306DD114C
DEFINE_HIDDEN_STRING(String3, 0x0D, ('E')('A')('4')('1')('8')('0')('2')('E')('7')('1')('1')('6')('F')('9')('E')('B')('E')('6')('7')('E')('5')('F')('F')('3')('0')('6')('D')('D')('1')('1')('4')('C'))
//F69C4741EFC4E791E3DF87E5BA7E3163
DEFINE_HIDDEN_STRING(String4, 0x3A, ('F')('6')('9')('C')('4')('7')('4')('1')('E')('F')('C')('4')('E')('7')('9')('1')('E')('3')('D')('F')('8')('7')('E')('5')('B')('A')('7')('E')('3')('1')('6')('3'))
//D53B26DF4C14F2E38B16E2164179D294
DEFINE_HIDDEN_STRING(String5, 0x07, ('D')('5')('3')('B')('2')('6')('D')('F')('4')('C')('1')('4')('F')('2')('E')('3')('8')('B')('1')('6')('E')('2')('1')('6')('4')('1')('7')('9')('D')('2')('9')('4'))
//0A639135FAD8C642E48E6E18346CEE2F
DEFINE_HIDDEN_STRING(String6, 0x7A, ('0')('A')('6')('3')('9')('1')('3')('5')('F')('A')('D')('8')('C')('6')('4')('2')('E')('4')('8')('E')('6')('E')('1')('8')('3')('4')('6')('C')('E')('E')('2')('F'))
//5C77CA0CD6E4C43A4ED2457380956432
DEFINE_HIDDEN_STRING(String7, 0x3C, ('5')('C')('7')('7')('C')('A')('0')('C')('D')('6')('E')('4')('C')('4')('3')('A')('4')('E')('D')('2')('4')('5')('7')('3')('8')('0')('9')('5')('6')('4')('3')('2'))
//3ABF2550FE1CB2C01224A00EA6744B21
DEFINE_HIDDEN_STRING(String8, 0x20, ('3')('A')('B')('F')('2')('5')('5')('0')('F')('E')('1')('C')('B')('2')('C')('0')('1')('2')('2')('4')('A')('0')('0')('E')('A')('6')('7')('4')('4')('B')('2')('1'))

std::string KleverKeys::get(std::string id) {

    std::string upperId = EasyEncrypt::Utils::toUpperCase(id);
    std::string hashedId = EasyEncrypt::Utils::toUpperCase(EasyEncrypt::SHA::Hex::hash256((char*) upperId.c_str()));


    if(hashedId == "4FBC1FEB5755103D6B5ED27396ED6D4205AFE1895EA5425237BB39BCD6688329") {
        return GetString1();
    } else if(hashedId == "F9683B7831D8422D217706FBE50C8C78BB2EC39E2B7D4BD0C8C627A2A4CFCC0") {
        return GetString2();
    } else if(hashedId == "AFBF5AA54DD765A86B670B882462009CCFD640951C17372C7CC5AC0533F0F65") {
        return GetString3();
    } else if(hashedId == "42E44591661F11E133A333D9945535D54985E6169A2440C3D5B9E7E94512CE21") {
        return GetString4();
    } else if(hashedId == "A83276F34CF4A30376C90EA7E3C0D0C76DA43CC46876B5AF56699CB028AF05F4") {
        return GetString5();
    } else if(hashedId == "BFCCF9E6F6546D27A7C2391CF2EB6FE7D278FCF0D9AD573E2CA7BF8A17B18451") {
        return GetString6();
    } else if(hashedId == "711BD7C6C2DCA0A1558D5B9745241024BA68BC152E3A6F455D8FABEF0027FEE4") {
        return GetString7();
    } else if(hashedId == "3D4F6A1DEA2773EECE5CED74D4E1474C2EF24C6EF50A1B635755A042C8C2E056") {
        return GetString8();
    }


    //return a random hex value, disguised as a 32 bit hex key.
    return EasyEncrypt::Utils::toUpperCase(EasyEncrypt::Random::secureEncoded(EasyEncrypt::HEX, 32).c_str());


}
