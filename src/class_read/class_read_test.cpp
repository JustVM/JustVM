//
// Created by 刘丰恺 on 2016/12/1.
//

#include "../utils/mem_zip/unzipper.h"
#include "class_reader.h"
#include "class_file.h"
#include <iostream>
#include <cinttypes>

using std::cout;
using std::endl;

using zipper::Unzipper;
using zipper::ZipEntry;

#define TEST(STRUCT) \
{ \
    STRUCT temp; \
    cout << #STRUCT << " " << sizeof(temp) << endl; \
}


int main90(int argc, char **argv) {
//    cp_item pool;
//    pool.meta_info.tag = cp_tag::CONSTANT_Utf8;
//    cout << sizeof(pool);
    TEST(CONSTANT_Meta_info);
    TEST(CONSTANT_Class_info);
    TEST(CONSTANT_Fieldref_info);
    TEST(CONSTANT_Methodref_info);
    TEST(CONSTANT_InterfaceMethodref_info);
    TEST(CONSTANT_String_info);
    TEST(CONSTANT_Integer_info);
    TEST(CONSTANT_Float_info);
    TEST(CONSTANT_Long_info);
    TEST(CONSTANT_Double_info);
    TEST(CONSTANT_NameAndType_info);
    TEST(CONSTANT_Utf8_info);
    TEST(CONSTANT_MethodHandle_info);
    TEST(CONSTANT_MethodType_info);
    TEST(CONSTANT_InvokeDynamic_info);
    TEST(cp_item);

    af_item item(0x1020);
    cout << "Af validation: " << item.check_af_valid() << endl;
    cout << "ACC_PUBLIC :" << item.is_flag_ext<af_tag::ACC_PUBLIC>() << endl;
    cout << "ACC_SYNTHETIC: " << item.is_flag_ext<af_tag::ACC_SYNTHETIC>() << endl;

    return 0;
}

int main() {

    std::string dir = "/Library/Java/JavaVirtualMachines/jdk1.8.0_51.jdk/Contents/Home/jre/lib/rt.jar";

    Unzipper unzipper(dir);
    std::vector<ZipEntry> entries = unzipper.entries();

    std::vector<byte> unzipped_entry;

    unzipper.extractEntryToMemory("java/lang/String$1.class", unzipped_entry);

//    for (int i = 0; i < unzipped_entry.size(); ++i) {
//        printf("%x ", unzipped_entry[i]);
//    }

    bytes_reader reader(std::cref(unzipped_entry));

//    printf("%x" " \n", reader.readType<uint32>());
//    printf("%" PRIu16 " \n", reader.readType<uint16>());
//    printf("%" PRIu16 "\n", reader.readType<uint16>());
//    printf("%" PRIu16 "\n", reader.readType<uint16>());
    class_file classFile;
    classFile.setMagic(reader.read_bytes_with_type<uint32>());
    classFile.setMinorVersion(reader.read_bytes_with_type<uint16>());
    classFile.setMajorVersion(reader.read_bytes_with_type<uint16>());
    classFile.setConstantPoolCount(reader.read_bytes_with_type<uint16>());

//    cp_item *cp_null_item = nullptr;
//    classFile.insert_item_to_cp(cp_null_item);
//    for (int i = 0; i < classFile.getConstantPoolCount() - 1; ++i) {
//        classFile.insert_item_to_cp(read_cp_item_from_bytes(reader, reader.read_bytes_with_type<uint8>()));
//    }
    // dev

    return 0;
}