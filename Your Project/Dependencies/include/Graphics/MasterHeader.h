#ifndef _MASTERHEADER_H_
#define _MASTERHEADER_H_
#pragma once

#include <glm/ext.hpp>

#include <memory>
#include <vector>
#include <map>

//#include <string>

#define PI glm::pi<float>()

//#include <memory>
#ifdef _MEMORY_

using std::unique_ptr;
using std::make_unique;

using std::shared_ptr;
using std::make_shared;

using std::weak_ptr;

#endif

//#include <string>
#ifdef _STRING_

using std::string;
using std::to_string;

#ifdef _MEMORY_

typedef unique_ptr<string> stringPtrU;
typedef shared_ptr<string> stringPtrS;
typedef weak_ptr<string> stringPtrW;

#endif

#endif

//#include <vector>
#ifdef _VECTOR_

template<typename T>
using List = std::vector<T>;

//#include <memory>
#ifdef _MEMORY_

template <typename T>
using ListPtrU = unique_ptr<List<T>>;
template <typename T>
using ListPtrS = shared_ptr<List<T>>;
template <typename T>
using ListPtrW = weak_ptr<List<T>>;

#endif

#endif

//#include <map>
#ifdef _MAP_

template<typename T, typename U>
using Dictionary = std::map<T, U>;

//#include <memory>
#ifdef _MEMORY_

template<typename T, typename U>
using DictionaryPtrU = unique_ptr<Dictionary<T, U>>;
template<typename T, typename U>
using DictionaryPtrS = shared_ptr<Dictionary<T, U>>;
template<typename T, typename U>
using DictionaryPtrW = weak_ptr<Dictionary<T, U>>;

#endif

#endif

//#include <glm/detail/type_vec.hpp>
__if_exists(glm::vec2)
{
	using Vector2 = glm::vec2;
	using Vector3 = glm::vec3;
	using Vector4 = glm::vec4;

//#include <memory>
	#ifdef _MEMORY_

	typedef unique_ptr<Vector2> Vector2PtrU;
	typedef shared_ptr<Vector2> Vector2PtrS;
	typedef weak_ptr<Vector2> Vector2PtrW;

	typedef unique_ptr<Vector3> Vector3PtrU;
	typedef shared_ptr<Vector3> Vector3PtrS;
	typedef weak_ptr<Vector3> Vector3PtrW;

	typedef unique_ptr<Vector4> Vector4PtrU;
	typedef shared_ptr<Vector4> Vector4PtrS;
	typedef weak_ptr<Vector4> Vector4PtrW;

	#endif
}

//#include <glm/detail/type_vec.hpp>
__if_exists(glm::vec2)
{
	using UVector2 = glm::uvec2;
	using UVector3 = glm::uvec3;
	using UVector4 = glm::uvec4;

	//#include <memory>
	#ifdef _MEMORY_

	typedef unique_ptr<UVector2> UVector2PtrU;
	typedef shared_ptr<UVector2> UVector2PtrS;
	typedef weak_ptr<UVector2> UVector2PtrW;

	typedef unique_ptr<UVector3> UVector3PtrU;
	typedef shared_ptr<UVector3> UVector3PtrS;
	typedef weak_ptr<UVector3> UVector3PtrW;

	typedef unique_ptr<UVector4> UVector4PtrU;
	typedef shared_ptr<UVector4> UVector4PtrS;
	typedef weak_ptr<UVector4> UVector4PtrW;

	#endif
}

//#include <glm/detail/type_mat4x4.hpp>
__if_exists(glm::mat4)
{
	using Matrix4x4 = glm::mat4x4;

	//#include <memory>
	#ifdef _MEMORY_

	typedef unique_ptr<Matrix4x4> Matrix4x4PtrU;
	typedef shared_ptr<Matrix4x4> Matrix4x4PtrS;
	typedef weak_ptr<Matrix4x4> Matrix4x4PtrW;

	#endif
}


#endif // _MASTERHEADER_H_
