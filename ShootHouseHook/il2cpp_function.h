DO_FUNC(Unity_Array*, FindObjectsOfType, (void*), "UnityEngine.CoreModule", "UnityEngine", "Object", "Object[] FindObjectsOfType(Type type);");
DO_FUNC(void*, GetType, (void*), "mscorlib", "System", "Type", "Type GetType(String typeName);");
DO_FUNC(void*, PtrToStringAnsi, (const char*), "mscorlib", "System.Runtime.InteropServices", "Marshal", "String PtrToStringAnsi(IntPtr ptr);");

DO_FUNC(Camera*, GetMainCamera, (), "UnityEngine.CoreModule", "UnityEngine", "Camera", "Camera get_main();");

DO_FUNC(Transform*, GetTransform, (GameObject*), "UnityEngine.CoreModule", "UnityEngine", "GameObject", "Transform get_transform();");
DO_FUNC(Vector3, GetPosition, (Transform*), "UnityEngine.CoreModule", "UnityEngine", "Transform", "Vector3 get_position();");