

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from MedicalDemoInfo.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef MedicalDemoInfo_1981364279_h
#define MedicalDemoInfo_1981364279_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#include "rti/xcdr/Interpreter.hpp"
#else
#include "ndds_standalone_type.h"
#endif

extern "C" {

    extern const char *Patient_ID_tTYPENAME;

}

struct Patient_ID_tSeq;
#ifndef NDDS_STANDALONE_TYPE
class Patient_ID_tTypeSupport;
class Patient_ID_tDataWriter;
class Patient_ID_tDataReader;
#endif
class Patient_ID_t 
{
  public:
    typedef struct Patient_ID_tSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef Patient_ID_tTypeSupport TypeSupport;
    typedef Patient_ID_tDataWriter DataWriter;
    typedef Patient_ID_tDataReader DataReader;
    #endif

    DDS_Char *   Id ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode* Patient_ID_t_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *Patient_ID_t_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *Patient_ID_t_get_sample_access_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *Patient_ID_t_get_sample_seq_access_info(void);
#endif

DDS_SEQUENCE(Patient_ID_tSeq, Patient_ID_t);

NDDSUSERDllExport
RTIBool Patient_ID_t_initialize(
    Patient_ID_t* self);

NDDSUSERDllExport
RTIBool Patient_ID_t_initialize_ex(
    Patient_ID_t* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Patient_ID_t_initialize_w_params(
    Patient_ID_t* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool Patient_ID_t_finalize_w_return(
    Patient_ID_t* self);

NDDSUSERDllExport
void Patient_ID_t_finalize(
    Patient_ID_t* self);

NDDSUSERDllExport
void Patient_ID_t_finalize_ex(
    Patient_ID_t* self,RTIBool deletePointers);

NDDSUSERDllExport
void Patient_ID_t_finalize_w_params(
    Patient_ID_t* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Patient_ID_t_finalize_optional_members(
    Patient_ID_t* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Patient_ID_t_copy(
    Patient_ID_t* dst,
    const Patient_ID_t* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
extern "C" {

    extern const char *PatientInfoTYPENAME;

}

struct PatientInfoSeq;
#ifndef NDDS_STANDALONE_TYPE
class PatientInfoTypeSupport;
class PatientInfoDataWriter;
class PatientInfoDataReader;
#endif
class PatientInfo 
: public Patient_ID_t{
  public:
    typedef struct PatientInfoSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef PatientInfoTypeSupport TypeSupport;
    typedef PatientInfoDataWriter DataWriter;
    typedef PatientInfoDataReader DataReader;
    #endif

    DDS_Char *   FirstName ;
    DDS_Char *   LastName ;
    DDS_UnsignedLong   Age ;
    DDS_UnsignedLong   HeightCm ;
    DDS_UnsignedLong   WeightKg ;
    DDS_Char *   Sex ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode* PatientInfo_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *PatientInfo_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *PatientInfo_get_sample_access_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *PatientInfo_get_sample_seq_access_info(void);
#endif

DDS_SEQUENCE(PatientInfoSeq, PatientInfo);

NDDSUSERDllExport
RTIBool PatientInfo_initialize(
    PatientInfo* self);

NDDSUSERDllExport
RTIBool PatientInfo_initialize_ex(
    PatientInfo* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool PatientInfo_initialize_w_params(
    PatientInfo* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool PatientInfo_finalize_w_return(
    PatientInfo* self);

NDDSUSERDllExport
void PatientInfo_finalize(
    PatientInfo* self);

NDDSUSERDllExport
void PatientInfo_finalize_ex(
    PatientInfo* self,RTIBool deletePointers);

NDDSUSERDllExport
void PatientInfo_finalize_w_params(
    PatientInfo* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void PatientInfo_finalize_optional_members(
    PatientInfo* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool PatientInfo_copy(
    PatientInfo* dst,
    const PatientInfo* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#ifndef NDDS_STANDALONE_TYPE
namespace rti { 
    namespace xcdr {
        template <>
        struct type_code<Patient_ID_t> {
            static const RTIXCdrTypeCode * get();
        };

        template <>
        struct type_code<PatientInfo> {
            static const RTIXCdrTypeCode * get();
        };

    } 
}

#endif

#endif /* MedicalDemoInfo */

