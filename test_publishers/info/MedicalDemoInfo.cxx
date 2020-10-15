

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from MedicalDemoInfo.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#ifndef dds_c_log_impl_h              
#include "dds_c/dds_c_log_impl.h"                                
#endif 
#ifndef dds_c_log_infrastructure_h                      
#include "dds_c/dds_c_infrastructure_impl.h"       
#endif 

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif    

#ifndef osapi_heap_h
#include "osapi/osapi_heap.h" 
#endif
#else
#include "ndds_standalone_type.h"
#endif

#include "MedicalDemoInfo.h"

#ifndef NDDS_STANDALONE_TYPE
#include "MedicalDemoInfoPlugin.h"
#endif

#include <new>

/* ========================================================================= */
const char *Patient_ID_tTYPENAME = "Patient_ID_t";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* Patient_ID_t_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Patient_ID_t_g_tc_Id_string = DDS_INITIALIZE_STRING_TYPECODE((32));

    static DDS_TypeCode_Member Patient_ID_t_g_tc_members[1]=
    {

        {
            (char *)"Id",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_KEY_MEMBER , /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode Patient_ID_t_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Patient_ID_t", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            1, /* Number of members */
            Patient_ID_t_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for Patient_ID_t*/

    if (is_initialized) {
        return &Patient_ID_t_g_tc;
    }

    Patient_ID_t_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    Patient_ID_t_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&Patient_ID_t_g_tc_Id_string;

    /* Initialize the values for member annotations. */
    Patient_ID_t_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    Patient_ID_t_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

    Patient_ID_t_g_tc._data._sampleAccessInfo =
    Patient_ID_t_get_sample_access_info();
    Patient_ID_t_g_tc._data._typePlugin =
    Patient_ID_t_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &Patient_ID_t_g_tc;
}

#define TSeq Patient_ID_tSeq
#define T Patient_ID_t
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *Patient_ID_t_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo Patient_ID_t_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(Patient_ID_tSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        Patient_ID_tSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &Patient_ID_t_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *Patient_ID_t_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    Patient_ID_t *sample;

    static RTIXCdrMemberAccessInfo Patient_ID_t_g_memberAccessInfos[1] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo Patient_ID_t_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &Patient_ID_t_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        Patient_ID_t);
    if (sample == NULL) {
        return NULL;
    }

    Patient_ID_t_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->Id - (char *)sample);

    Patient_ID_t_g_sampleAccessInfo.memberAccessInfos = 
    Patient_ID_t_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(Patient_ID_t);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            Patient_ID_t_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            Patient_ID_t_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    Patient_ID_t_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    Patient_ID_t_g_sampleAccessInfo.getMemberValuePointerFcn = 
    Patient_ID_t_get_member_value_pointer;

    Patient_ID_t_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &Patient_ID_t_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *Patient_ID_t_get_type_plugin_info()
{
    static RTIXCdrTypePlugin Patient_ID_t_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        Patient_ID_t_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        Patient_ID_t_finalize_w_return,
        NULL
    };

    return &Patient_ID_t_g_typePlugin;
}
#endif

RTIBool Patient_ID_t_initialize(
    Patient_ID_t* sample) {
    return Patient_ID_t_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool Patient_ID_t_initialize_ex(
    Patient_ID_t* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return Patient_ID_t_initialize_w_params(
        sample,&allocParams);

}

RTIBool Patient_ID_t_initialize_w_params(
    Patient_ID_t* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (allocParams->allocate_memory) {
        sample->Id = DDS_String_alloc((32));
        RTICdrType_copyStringEx(
            &sample->Id,
            "",
            (32),
            RTI_FALSE);
        if (sample->Id == NULL) {
            return RTI_FALSE;
        }
    } else {
        if (sample->Id != NULL) {
            RTICdrType_copyStringEx(
                &sample->Id,
                "",
                (32),
                RTI_FALSE);
            if (sample->Id == NULL) {
                return RTI_FALSE;
            }
        }
    }

    return RTI_TRUE;
}

RTIBool Patient_ID_t_finalize_w_return(
    Patient_ID_t* sample)
{
    Patient_ID_t_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void Patient_ID_t_finalize(
    Patient_ID_t* sample)
{

    Patient_ID_t_finalize_ex(sample,RTI_TRUE);
}

void Patient_ID_t_finalize_ex(
    Patient_ID_t* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    Patient_ID_t_finalize_w_params(
        sample,&deallocParams);
}

void Patient_ID_t_finalize_w_params(
    Patient_ID_t* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

    if (sample->Id != NULL) {
        DDS_String_free(sample->Id);
        sample->Id=NULL;

    }
}

void Patient_ID_t_finalize_optional_members(
    Patient_ID_t* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool Patient_ID_t_copy(
    Patient_ID_t* dst,
    const Patient_ID_t* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!RTICdrType_copyStringEx (
            &dst->Id, src->Id, 
            (32) + 1, RTI_FALSE)){
            return RTI_FALSE;
        }

        return RTI_TRUE;

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'Patient_ID_t' sequence class.
*/
#define T Patient_ID_t
#define TSeq Patient_ID_tSeq

#define T_initialize_w_params Patient_ID_t_initialize_w_params

#define T_finalize_w_params   Patient_ID_t_finalize_w_params
#define T_copy       Patient_ID_t_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

/* ========================================================================= */
const char *PatientInfoTYPENAME = "PatientInfo";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* PatientInfo_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode PatientInfo_g_tc_FirstName_string = DDS_INITIALIZE_STRING_TYPECODE((32));
    static DDS_TypeCode PatientInfo_g_tc_LastName_string = DDS_INITIALIZE_STRING_TYPECODE((32));
    static DDS_TypeCode PatientInfo_g_tc_Sex_string = DDS_INITIALIZE_STRING_TYPECODE((32));

    static DDS_TypeCode_Member PatientInfo_g_tc_members[6]=
    {

        {
            (char *)"FirstName",/* Member name */
            {
                1,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"LastName",/* Member name */
            {
                2,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"Age",/* Member name */
            {
                3,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"HeightCm",/* Member name */
            {
                4,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"WeightKg",/* Member name */
            {
                5,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"Sex",/* Member name */
            {
                6,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode PatientInfo_g_tc =
    {{
            DDS_TK_VALUE, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"PatientInfo", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            6, /* Number of members */
            PatientInfo_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for PatientInfo*/

    if (is_initialized) {
        return &PatientInfo_g_tc;
    }

    PatientInfo_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    PatientInfo_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&PatientInfo_g_tc_FirstName_string;
    PatientInfo_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&PatientInfo_g_tc_LastName_string;
    PatientInfo_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong_w_new;
    PatientInfo_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong_w_new;
    PatientInfo_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong_w_new;
    PatientInfo_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&PatientInfo_g_tc_Sex_string;

    /* Initialize the values for member annotations. */
    PatientInfo_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    PatientInfo_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

    PatientInfo_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    PatientInfo_g_tc_members[1]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

    PatientInfo_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
    PatientInfo_g_tc_members[2]._annotations._defaultValue._u.ulong_value = 0u;
    PatientInfo_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
    PatientInfo_g_tc_members[2]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
    PatientInfo_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
    PatientInfo_g_tc_members[2]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

    PatientInfo_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
    PatientInfo_g_tc_members[3]._annotations._defaultValue._u.ulong_value = 0u;
    PatientInfo_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
    PatientInfo_g_tc_members[3]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
    PatientInfo_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
    PatientInfo_g_tc_members[3]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

    PatientInfo_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
    PatientInfo_g_tc_members[4]._annotations._defaultValue._u.ulong_value = 0u;
    PatientInfo_g_tc_members[4]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
    PatientInfo_g_tc_members[4]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
    PatientInfo_g_tc_members[4]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
    PatientInfo_g_tc_members[4]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

    PatientInfo_g_tc_members[5]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    PatientInfo_g_tc_members[5]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

    PatientInfo_g_tc._data._typeCode = (RTICdrTypeCode *)Patient_ID_t_get_typecode(); /* Base class */

    PatientInfo_g_tc._data._sampleAccessInfo =
    PatientInfo_get_sample_access_info();
    PatientInfo_g_tc._data._typePlugin =
    PatientInfo_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &PatientInfo_g_tc;
}

#define TSeq PatientInfoSeq
#define T PatientInfo
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *PatientInfo_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo PatientInfo_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(PatientInfoSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        PatientInfoSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &PatientInfo_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *PatientInfo_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    PatientInfo *sample;

    static RTIXCdrMemberAccessInfo PatientInfo_g_memberAccessInfos[6] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo PatientInfo_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &PatientInfo_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        PatientInfo);
    if (sample == NULL) {
        return NULL;
    }

    PatientInfo_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->FirstName - (char *)sample);

    PatientInfo_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->LastName - (char *)sample);

    PatientInfo_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->Age - (char *)sample);

    PatientInfo_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->HeightCm - (char *)sample);

    PatientInfo_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->WeightKg - (char *)sample);

    PatientInfo_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->Sex - (char *)sample);

    PatientInfo_g_sampleAccessInfo.memberAccessInfos = 
    PatientInfo_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(PatientInfo);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            PatientInfo_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            PatientInfo_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    PatientInfo_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
    RTI_XCDR_TRUE;

    PatientInfo_g_sampleAccessInfo.getMemberValuePointerFcn = 
    PatientInfo_get_member_value_pointer;

    PatientInfo_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &PatientInfo_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *PatientInfo_get_type_plugin_info()
{
    static RTIXCdrTypePlugin PatientInfo_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        PatientInfo_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        PatientInfo_finalize_w_return,
        NULL
    };

    return &PatientInfo_g_typePlugin;
}
#endif

RTIBool PatientInfo_initialize(
    PatientInfo* sample) {
    return PatientInfo_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool PatientInfo_initialize_ex(
    PatientInfo* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return PatientInfo_initialize_w_params(
        sample,&allocParams);

}

RTIBool PatientInfo_initialize_w_params(
    PatientInfo* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }
    if (!Patient_ID_t_initialize_w_params((Patient_ID_t*)sample,allocParams)) {
        return RTI_FALSE;
    }

    if (allocParams->allocate_memory) {
        sample->FirstName = DDS_String_alloc((32));
        RTICdrType_copyStringEx(
            &sample->FirstName,
            "",
            (32),
            RTI_FALSE);
        if (sample->FirstName == NULL) {
            return RTI_FALSE;
        }
    } else {
        if (sample->FirstName != NULL) {
            RTICdrType_copyStringEx(
                &sample->FirstName,
                "",
                (32),
                RTI_FALSE);
            if (sample->FirstName == NULL) {
                return RTI_FALSE;
            }
        }
    }

    if (allocParams->allocate_memory) {
        sample->LastName = DDS_String_alloc((32));
        RTICdrType_copyStringEx(
            &sample->LastName,
            "",
            (32),
            RTI_FALSE);
        if (sample->LastName == NULL) {
            return RTI_FALSE;
        }
    } else {
        if (sample->LastName != NULL) {
            RTICdrType_copyStringEx(
                &sample->LastName,
                "",
                (32),
                RTI_FALSE);
            if (sample->LastName == NULL) {
                return RTI_FALSE;
            }
        }
    }

    sample->Age = 0u;

    sample->HeightCm = 0u;

    sample->WeightKg = 0u;

    if (allocParams->allocate_memory) {
        sample->Sex = DDS_String_alloc((32));
        RTICdrType_copyStringEx(
            &sample->Sex,
            "",
            (32),
            RTI_FALSE);
        if (sample->Sex == NULL) {
            return RTI_FALSE;
        }
    } else {
        if (sample->Sex != NULL) {
            RTICdrType_copyStringEx(
                &sample->Sex,
                "",
                (32),
                RTI_FALSE);
            if (sample->Sex == NULL) {
                return RTI_FALSE;
            }
        }
    }

    return RTI_TRUE;
}

RTIBool PatientInfo_finalize_w_return(
    PatientInfo* sample)
{
    PatientInfo_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void PatientInfo_finalize(
    PatientInfo* sample)
{

    PatientInfo_finalize_ex(sample,RTI_TRUE);
}

void PatientInfo_finalize_ex(
    PatientInfo* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    PatientInfo_finalize_w_params(
        sample,&deallocParams);
}

void PatientInfo_finalize_w_params(
    PatientInfo* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }
    Patient_ID_t_finalize_w_params((Patient_ID_t*)sample,deallocParams);

    if (sample->FirstName != NULL) {
        DDS_String_free(sample->FirstName);
        sample->FirstName=NULL;

    }
    if (sample->LastName != NULL) {
        DDS_String_free(sample->LastName);
        sample->LastName=NULL;

    }

    if (sample->Sex != NULL) {
        DDS_String_free(sample->Sex);
        sample->Sex=NULL;

    }
}

void PatientInfo_finalize_optional_members(
    PatientInfo* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    Patient_ID_t_finalize_optional_members((Patient_ID_t*)sample,deletePointers);

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool PatientInfo_copy(
    PatientInfo* dst,
    const PatientInfo* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if(!Patient_ID_t_copy((Patient_ID_t*)dst,(const Patient_ID_t*)src)) {
            return RTI_FALSE;
        }

        if (!RTICdrType_copyStringEx (
            &dst->FirstName, src->FirstName, 
            (32) + 1, RTI_FALSE)){
            return RTI_FALSE;
        }
        if (!RTICdrType_copyStringEx (
            &dst->LastName, src->LastName, 
            (32) + 1, RTI_FALSE)){
            return RTI_FALSE;
        }
        if (!RTICdrType_copyUnsignedLong (
            &dst->Age, &src->Age)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyUnsignedLong (
            &dst->HeightCm, &src->HeightCm)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyUnsignedLong (
            &dst->WeightKg, &src->WeightKg)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyStringEx (
            &dst->Sex, src->Sex, 
            (32) + 1, RTI_FALSE)){
            return RTI_FALSE;
        }

        return RTI_TRUE;

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'PatientInfo' sequence class.
*/
#define T PatientInfo
#define TSeq PatientInfoSeq

#define T_initialize_w_params PatientInfo_initialize_w_params

#define T_finalize_w_params   PatientInfo_finalize_w_params
#define T_copy       PatientInfo_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

#ifndef NDDS_STANDALONE_TYPE
namespace rti { 
    namespace xcdr {
        const RTIXCdrTypeCode * type_code<Patient_ID_t>::get() 
        {
            return (const RTIXCdrTypeCode *) Patient_ID_t_get_typecode();
        }

        const RTIXCdrTypeCode * type_code<PatientInfo>::get() 
        {
            return (const RTIXCdrTypeCode *) PatientInfo_get_typecode();
        }

    } 
}
#endif
