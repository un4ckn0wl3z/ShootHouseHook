#pragma once

// assembly
DO_API(const Il2CppImage*, il2cpp_assembly_get_image, (const Il2CppAssembly* assembly));

// class
DO_API(void, il2cpp_class_for_each, (void(*klassReportFunc)(Il2CppClass* klass, void* userData), void* userData));
DO_API(const Il2CppType*, il2cpp_class_enum_basetype, (Il2CppClass* klass));
DO_API(bool, il2cpp_class_is_generic, (const Il2CppClass* klass));
DO_API(bool, il2cpp_class_is_inflated, (const Il2CppClass* klass));
DO_API(bool, il2cpp_class_is_assignable_from, (Il2CppClass* klass, Il2CppClass* oklass));
DO_API(bool, il2cpp_class_is_subclass_of, (Il2CppClass* klass, Il2CppClass* klassc, bool check_interfaces));
DO_API(bool, il2cpp_class_has_parent, (Il2CppClass* klass, Il2CppClass* klassc));
DO_API(Il2CppClass*, il2cpp_class_from_il2cpp_type, (const Il2CppType* type));
DO_API(Il2CppClass*, il2cpp_class_from_name, (const Il2CppImage* image, const char* namespaze, const char* name));
DO_API(Il2CppClass*, il2cpp_class_from_system_type, (Il2CppReflectionType* type));
DO_API(Il2CppClass*, il2cpp_class_get_element_class, (Il2CppClass* klass));
DO_API(const EventInfo*, il2cpp_class_get_events, (Il2CppClass* klass, void** iter));
DO_API(FieldInfo*, il2cpp_class_get_fields, (Il2CppClass* klass, void** iter));
DO_API(Il2CppClass*, il2cpp_class_get_nested_types, (Il2CppClass* klass, void** iter));
DO_API(Il2CppClass*, il2cpp_class_get_interfaces, (Il2CppClass* klass, void** iter));
DO_API(const PropertyInfo*, il2cpp_class_get_properties, (Il2CppClass* klass, void** iter));
DO_API(const PropertyInfo*, il2cpp_class_get_property_from_name, (Il2CppClass* klass, const char* name));
DO_API(FieldInfo*, il2cpp_class_get_field_from_name, (Il2CppClass* klass, const char* name));
DO_API(const MethodInfo*, il2cpp_class_get_methods, (Il2CppClass* klass, void** iter));
DO_API(const MethodInfo*, il2cpp_class_get_method_from_name, (Il2CppClass* klass, const char* name, int argsCount));
DO_API(const char*, il2cpp_class_get_name, (Il2CppClass* klass));
DO_API(void, il2cpp_type_get_name_chunked, (const Il2CppType* type, void(*chunkReportFunc)(void* data, void* userData), void* userData));
DO_API(const char*, il2cpp_class_get_namespace, (Il2CppClass* klass));
DO_API(Il2CppClass*, il2cpp_class_get_parent, (Il2CppClass* klass));
DO_API(Il2CppClass*, il2cpp_class_get_declaring_type, (Il2CppClass* klass));
DO_API(int32_t, il2cpp_class_instance_size, (Il2CppClass* klass));
DO_API(size_t, il2cpp_class_num_fields, (const Il2CppClass* enumKlass));
DO_API(bool, il2cpp_class_is_valuetype, (const Il2CppClass* klass));
DO_API(int32_t, il2cpp_class_value_size, (Il2CppClass* klass, uint32_t* align));
DO_API(bool, il2cpp_class_is_blittable, (const Il2CppClass* klass));
DO_API(int, il2cpp_class_get_flags, (const Il2CppClass* klass));
DO_API(bool, il2cpp_class_is_abstract, (const Il2CppClass* klass));
DO_API(bool, il2cpp_class_is_interface, (const Il2CppClass* klass));
DO_API(int, il2cpp_class_array_element_size, (const Il2CppClass* klass));
DO_API(Il2CppClass*, il2cpp_class_from_type, (const Il2CppType* type));
DO_API(const Il2CppType*, il2cpp_class_get_type, (Il2CppClass* klass));
DO_API(uint32_t, il2cpp_class_get_type_token, (Il2CppClass* klass));
DO_API(bool, il2cpp_class_has_attribute, (Il2CppClass* klass, Il2CppClass* attr_class));
DO_API(bool, il2cpp_class_has_references, (Il2CppClass* klass));
DO_API(bool, il2cpp_class_is_enum, (const Il2CppClass* klass));
DO_API(const Il2CppImage*, il2cpp_class_get_image, (Il2CppClass* klass));
DO_API(const char*, il2cpp_class_get_assemblyname, (const Il2CppClass* klass));
DO_API(int, il2cpp_class_get_rank, (const Il2CppClass* klass));
DO_API(uint32_t, il2cpp_class_get_data_size, (const Il2CppClass* klass));
DO_API(void*, il2cpp_class_get_static_field_data, (const Il2CppClass* klass));

// domain
DO_API(Il2CppDomain*, il2cpp_domain_get, ());
DO_API(const Il2CppAssembly*, il2cpp_domain_assembly_open, (Il2CppDomain* domain, const char* name));
DO_API(const Il2CppAssembly**, il2cpp_domain_get_assemblies, (const Il2CppDomain* domain, size_t* size));

// field
DO_API(int, il2cpp_field_get_flags, (FieldInfo* field));
DO_API(const char*, il2cpp_field_get_name, (FieldInfo* field));
DO_API(Il2CppClass*, il2cpp_field_get_parent, (FieldInfo* field));
DO_API(size_t, il2cpp_field_get_offset, (FieldInfo* field));
DO_API(const Il2CppType*, il2cpp_field_get_type, (FieldInfo* field));
DO_API(void, il2cpp_field_get_value, (Il2CppObject* obj, FieldInfo* field, void* value));
DO_API(Il2CppObject*, il2cpp_field_get_value_object, (FieldInfo* field, Il2CppObject* obj));
DO_API(bool, il2cpp_field_has_attribute, (FieldInfo* field, Il2CppClass* attr_class));
DO_API(void, il2cpp_field_set_value, (Il2CppObject* obj, FieldInfo* field, void* value));
DO_API(void, il2cpp_field_static_get_value, (FieldInfo* field, void* value));
DO_API(void, il2cpp_field_static_set_value, (FieldInfo* field, void* value));
DO_API(void, il2cpp_field_set_value_object, (Il2CppObject* instance, FieldInfo* field, Il2CppObject* value));
DO_API(bool, il2cpp_field_is_literal, (FieldInfo* field));

// method
DO_API(const Il2CppType*, il2cpp_method_get_return_type, (const MethodInfo* method));
DO_API(Il2CppClass*, il2cpp_method_get_declaring_type, (const MethodInfo* method));
DO_API(const char*, il2cpp_method_get_name, (const MethodInfo* method));
DO_API(const MethodInfo*, il2cpp_method_get_from_reflection, (const Il2CppReflectionMethod* method));
DO_API(Il2CppReflectionMethod*, il2cpp_method_get_object, (const MethodInfo* method, Il2CppClass* refclass));
DO_API(bool, il2cpp_method_is_generic, (const MethodInfo* method));
DO_API(bool, il2cpp_method_is_inflated, (const MethodInfo* method));
DO_API(bool, il2cpp_method_is_instance, (const MethodInfo* method));
DO_API(uint32_t, il2cpp_method_get_param_count, (const MethodInfo* method));
DO_API(const Il2CppType*, il2cpp_method_get_param, (const MethodInfo* method, uint32_t index));
DO_API(Il2CppClass*, il2cpp_method_get_class, (const MethodInfo* method));
DO_API(bool, il2cpp_method_has_attribute, (const MethodInfo* method, Il2CppClass* attr_class));
DO_API(uint32_t, il2cpp_method_get_flags, (const MethodInfo* method, uint32_t* iflags));
DO_API(uint32_t, il2cpp_method_get_token, (const MethodInfo* method));
DO_API(const char*, il2cpp_method_get_param_name, (const MethodInfo* method, uint32_t index));

// property
DO_API(uint32_t, il2cpp_property_get_flags, (PropertyInfo* prop));
DO_API(const MethodInfo*, il2cpp_property_get_get_method, (PropertyInfo* prop));
DO_API(const MethodInfo*, il2cpp_property_get_set_method, (PropertyInfo* prop));
DO_API(const char*, il2cpp_property_get_name, (PropertyInfo* prop));
DO_API(Il2CppClass*, il2cpp_property_get_parent, (PropertyInfo* prop));

// thread
DO_API(Il2CppThread*, il2cpp_thread_current, ());
DO_API(Il2CppThread*, il2cpp_thread_attach, (Il2CppDomain* domain));
DO_API(void, il2cpp_thread_detach, (Il2CppThread* thread));

DO_API(Il2CppThread**, il2cpp_thread_get_all_attached_threads, (size_t* size));
DO_API(bool, il2cpp_is_vm_thread, (Il2CppThread* thread));

// type
DO_API(Il2CppObject*, il2cpp_type_get_object, (const Il2CppType* type));
DO_API(int, il2cpp_type_get_type, (const Il2CppType* type));
DO_API(Il2CppClass*, il2cpp_type_get_class_or_element_class, (const Il2CppType* type));
DO_API(char*, il2cpp_type_get_name, (const Il2CppType* type));
DO_API(bool, il2cpp_type_is_byref, (const Il2CppType* type));
DO_API(uint32_t, il2cpp_type_get_attrs, (const Il2CppType* type));
DO_API(bool, il2cpp_type_equals, (const Il2CppType* type, const Il2CppType* otherType));
DO_API(char*, il2cpp_type_get_assembly_qualified_name, (const Il2CppType* type));
DO_API(bool, il2cpp_type_is_static, (const Il2CppType* type));
DO_API(bool, il2cpp_type_is_pointer_type, (const Il2CppType* type));

// image
DO_API(const Il2CppAssembly*, il2cpp_image_get_assembly, (const Il2CppImage* image));
DO_API(const char*, il2cpp_image_get_name, (const Il2CppImage* image));
DO_API(const char*, il2cpp_image_get_filename, (const Il2CppImage* image));
DO_API(const MethodInfo*, il2cpp_image_get_entry_point, (const Il2CppImage* image));
DO_API(size_t, il2cpp_image_get_class_count, (const Il2CppImage* image));
DO_API(const Il2CppClass*, il2cpp_image_get_class, (const Il2CppImage* image, size_t index));

// object
DO_API(Il2CppClass*, il2cpp_object_get_class, (Il2CppObject* obj));
DO_API(uint32_t, il2cpp_object_get_size, (Il2CppObject* obj));
DO_API(const MethodInfo*, il2cpp_object_get_virtual_method, (Il2CppObject* obj, const MethodInfo* method));
DO_API(Il2CppObject*, il2cpp_object_new, (const Il2CppClass* klass));
DO_API(void*, il2cpp_object_unbox, (Il2CppObject* obj));