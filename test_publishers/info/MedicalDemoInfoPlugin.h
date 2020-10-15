

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from MedicalDemoInfo.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef MedicalDemoInfoPlugin_1981364279_h
#define MedicalDemoInfoPlugin_1981364279_h

#include "MedicalDemoInfo.h"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

extern "C" {

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct Patient_ID_t
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct Patient_ID_t)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * Patient_ID_t must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct Patient_ID_t.
    */
    typedef  class Patient_ID_t Patient_ID_tKeyHolder;

    #define Patient_ID_tPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define Patient_ID_tPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define Patient_ID_tPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define Patient_ID_tPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define Patient_ID_tPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define Patient_ID_tPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define Patient_ID_tPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern Patient_ID_t*
    Patient_ID_tPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern Patient_ID_t*
    Patient_ID_tPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Patient_ID_t*
    Patient_ID_tPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    Patient_ID_tPluginSupport_copy_data(
        Patient_ID_t *out,
        const Patient_ID_t *in);

    NDDSUSERDllExport extern void 
    Patient_ID_tPluginSupport_destroy_data_w_params(
        Patient_ID_t *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    Patient_ID_tPluginSupport_destroy_data_ex(
        Patient_ID_t *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    Patient_ID_tPluginSupport_destroy_data(
        Patient_ID_t *sample);

    NDDSUSERDllExport extern void 
    Patient_ID_tPluginSupport_print_data(
        const Patient_ID_t *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern Patient_ID_t*
    Patient_ID_tPluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern Patient_ID_t*
    Patient_ID_tPluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    Patient_ID_tPluginSupport_destroy_key_ex(
        Patient_ID_tKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    Patient_ID_tPluginSupport_destroy_key(
        Patient_ID_tKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    Patient_ID_tPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    Patient_ID_tPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    Patient_ID_tPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    Patient_ID_tPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    Patient_ID_tPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        Patient_ID_t *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    Patient_ID_tPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        Patient_ID_t *out,
        const Patient_ID_t *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    Patient_ID_tPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const Patient_ID_t *sample); 

    NDDSUSERDllExport extern RTIBool
    Patient_ID_tPlugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const Patient_ID_t *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool 
    Patient_ID_tPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        Patient_ID_t **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    Patient_ID_tPlugin_deserialize_from_cdr_buffer(
        Patient_ID_t *sample,
        const char * buffer,
        unsigned int length);    
    #ifndef NDDS_STANDALONE_TYPE
    NDDSUSERDllExport extern DDS_ReturnCode_t
    Patient_ID_tPlugin_data_to_string(
        const Patient_ID_t *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    Patient_ID_tPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    Patient_ID_tPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    Patient_ID_tPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    Patient_ID_tPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    Patient_ID_tPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        Patient_ID_t ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    Patient_ID_tPlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        Patient_ID_tKeyHolder *key, 
        const Patient_ID_t *instance);

    NDDSUSERDllExport extern RTIBool 
    Patient_ID_tPlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        Patient_ID_t *instance, 
        const Patient_ID_tKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    Patient_ID_tPlugin_instance_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        DDS_KeyHash_t *keyhash,
        const Patient_ID_t *instance,
        RTIEncapsulationId encapsulationId);

    NDDSUSERDllExport extern RTIBool 
    Patient_ID_tPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms *Patient_ID_tPlugin_get_programs();

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    Patient_ID_tPlugin_new(void);

    NDDSUSERDllExport extern void
    Patient_ID_tPlugin_delete(struct PRESTypePlugin *);

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct PatientInfo
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct PatientInfo)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * PatientInfo must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct PatientInfo.
    */
    typedef  class PatientInfo PatientInfoKeyHolder;

    #define PatientInfoPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define PatientInfoPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define PatientInfoPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define PatientInfoPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define PatientInfoPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define PatientInfoPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define PatientInfoPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PatientInfo*
    PatientInfoPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern PatientInfo*
    PatientInfoPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern PatientInfo*
    PatientInfoPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    PatientInfoPluginSupport_copy_data(
        PatientInfo *out,
        const PatientInfo *in);

    NDDSUSERDllExport extern void 
    PatientInfoPluginSupport_destroy_data_w_params(
        PatientInfo *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    PatientInfoPluginSupport_destroy_data_ex(
        PatientInfo *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    PatientInfoPluginSupport_destroy_data(
        PatientInfo *sample);

    NDDSUSERDllExport extern void 
    PatientInfoPluginSupport_print_data(
        const PatientInfo *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern PatientInfo*
    PatientInfoPluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern PatientInfo*
    PatientInfoPluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    PatientInfoPluginSupport_destroy_key_ex(
        PatientInfoKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    PatientInfoPluginSupport_destroy_key(
        PatientInfoKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    PatientInfoPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    PatientInfoPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    PatientInfoPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    PatientInfoPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    PatientInfoPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        PatientInfo *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    PatientInfoPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        PatientInfo *out,
        const PatientInfo *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    PatientInfoPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const PatientInfo *sample); 

    NDDSUSERDllExport extern RTIBool
    PatientInfoPlugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const PatientInfo *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool 
    PatientInfoPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        PatientInfo **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    PatientInfoPlugin_deserialize_from_cdr_buffer(
        PatientInfo *sample,
        const char * buffer,
        unsigned int length);    
    #ifndef NDDS_STANDALONE_TYPE
    NDDSUSERDllExport extern DDS_ReturnCode_t
    PatientInfoPlugin_data_to_string(
        const PatientInfo *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    PatientInfoPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    PatientInfoPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    PatientInfoPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    PatientInfoPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    PatientInfoPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        PatientInfo ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    PatientInfoPlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        PatientInfoKeyHolder *key, 
        const PatientInfo *instance);

    NDDSUSERDllExport extern RTIBool 
    PatientInfoPlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        PatientInfo *instance, 
        const PatientInfoKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    PatientInfoPlugin_instance_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        DDS_KeyHash_t *keyhash,
        const PatientInfo *instance,
        RTIEncapsulationId encapsulationId);

    NDDSUSERDllExport extern RTIBool 
    PatientInfoPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms *PatientInfoPlugin_get_programs();

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    PatientInfoPlugin_new(void);

    NDDSUSERDllExport extern void
    PatientInfoPlugin_delete(struct PRESTypePlugin *);

}

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* MedicalDemoInfoPlugin_1981364279_h */

