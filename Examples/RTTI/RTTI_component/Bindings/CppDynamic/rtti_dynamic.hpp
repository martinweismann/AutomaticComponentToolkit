/*++

Copyright (C) 2020 ADSK

All rights reserved.

This file has been generated by the Automatic Component Toolkit (ACT) version 1.7.0-develop.

Abstract: This is an autogenerated C++-Header file in order to allow an easy
 use of RTTI

Interface version: 1.0.0

*/

#ifndef __RTTI_CPPHEADER_DYNAMIC_CPP
#define __RTTI_CPPHEADER_DYNAMIC_CPP

#include "rtti_types.hpp"
#include "rtti_dynamic.h"


#ifdef _WIN32
#include <windows.h>
#else // _WIN32
#include <dlfcn.h>
#endif // _WIN32
#include <string>
#include <memory>
#include <vector>
#include <exception>

namespace RTTI {

/*************************************************************************************************************************
 Forward Declaration of all classes
**************************************************************************************************************************/
class CWrapper;
class CBase;
class CAnimal;
class CMammal;
class CReptile;
class CGiraffe;
class CTiger;
class CSnake;
class CTurtle;
class CAnimalIterator;
class CZoo;

/*************************************************************************************************************************
 Declaration of deprecated class types
**************************************************************************************************************************/
typedef CWrapper CRTTIWrapper;
typedef CBase CRTTIBase;
typedef CAnimal CRTTIAnimal;
typedef CMammal CRTTIMammal;
typedef CReptile CRTTIReptile;
typedef CGiraffe CRTTIGiraffe;
typedef CTiger CRTTITiger;
typedef CSnake CRTTISnake;
typedef CTurtle CRTTITurtle;
typedef CAnimalIterator CRTTIAnimalIterator;
typedef CZoo CRTTIZoo;

/*************************************************************************************************************************
 Declaration of shared pointer types
**************************************************************************************************************************/
typedef std::shared_ptr<CWrapper> PWrapper;
typedef std::shared_ptr<CBase> PBase;
typedef std::shared_ptr<CAnimal> PAnimal;
typedef std::shared_ptr<CMammal> PMammal;
typedef std::shared_ptr<CReptile> PReptile;
typedef std::shared_ptr<CGiraffe> PGiraffe;
typedef std::shared_ptr<CTiger> PTiger;
typedef std::shared_ptr<CSnake> PSnake;
typedef std::shared_ptr<CTurtle> PTurtle;
typedef std::shared_ptr<CAnimalIterator> PAnimalIterator;
typedef std::shared_ptr<CZoo> PZoo;

/*************************************************************************************************************************
 Declaration of deprecated shared pointer types
**************************************************************************************************************************/
typedef PWrapper PRTTIWrapper;
typedef PBase PRTTIBase;
typedef PAnimal PRTTIAnimal;
typedef PMammal PRTTIMammal;
typedef PReptile PRTTIReptile;
typedef PGiraffe PRTTIGiraffe;
typedef PTiger PRTTITiger;
typedef PSnake PRTTISnake;
typedef PTurtle PRTTITurtle;
typedef PAnimalIterator PRTTIAnimalIterator;
typedef PZoo PRTTIZoo;

/*************************************************************************************************************************
 rtti_cast Definition
**************************************************************************************************************************/
template <class T>
inline std::shared_ptr<T> rtti_cast(PBase obj);

/*************************************************************************************************************************
 classParam Definition
**************************************************************************************************************************/

template<class T> class classParam {
private:
	const T* m_ptr;

public:
	classParam(const T* ptr)
		: m_ptr (ptr)
	{
	}

	classParam(std::shared_ptr <T> sharedPtr)
		: m_ptr (sharedPtr.get())
	{
	}

	RTTIHandle GetHandle()
	{
		if (m_ptr != nullptr)
			return m_ptr->handle();
		return nullptr;
	}
};

/*************************************************************************************************************************
 Class ERTTIException 
**************************************************************************************************************************/
class ERTTIException : public std::exception {
protected:
	/**
	* Error code for the Exception.
	*/
	RTTIResult m_errorCode;
	/**
	* Error message for the Exception.
	*/
	std::string m_errorMessage;

public:
	/**
	* Exception Constructor.
	*/
	ERTTIException(RTTIResult errorCode, const std::string & sErrorMessage)
		: m_errorMessage("RTTI Error " + std::to_string(errorCode) + " (" + sErrorMessage + ")")
	{
		m_errorCode = errorCode;
	}

	/**
	* Returns error code
	*/
	RTTIResult getErrorCode() const noexcept
	{
		return m_errorCode;
	}

	/**
	* Returns error message
	*/
	const char* what() const noexcept
	{
		return m_errorMessage.c_str();
	}

};

/*************************************************************************************************************************
 Class CInputVector
**************************************************************************************************************************/
template <typename T>
class CInputVector {
private:
	
	const T* m_data;
	size_t m_size;
	
public:
	
	CInputVector( const std::vector<T>& vec)
		: m_data( vec.data() ), m_size( vec.size() )
	{
	}
	
	CInputVector( const T* in_data, size_t in_size)
		: m_data( in_data ), m_size(in_size )
	{
	}
	
	const T* data() const
	{
		return m_data;
	}
	
	size_t size() const
	{
		return m_size;
	}
	
};

// declare deprecated class name
template<typename T>
using CRTTIInputVector = CInputVector<T>;

/*************************************************************************************************************************
 Class CWrapper 
**************************************************************************************************************************/
class CWrapper {
public:
	
	CWrapper(void* pSymbolLookupMethod)
	{
		CheckError(nullptr, initWrapperTable(&m_WrapperTable));
		CheckError(nullptr, loadWrapperTableFromSymbolLookupMethod(&m_WrapperTable, pSymbolLookupMethod));
		
		CheckError(nullptr, checkBinaryVersion());
	}
	
	CWrapper(const std::string &sFileName)
	{
		CheckError(nullptr, initWrapperTable(&m_WrapperTable));
		CheckError(nullptr, loadWrapperTable(&m_WrapperTable, sFileName.c_str()));
		
		CheckError(nullptr, checkBinaryVersion());
	}
	
	static PWrapper loadLibrary(const std::string &sFileName)
	{
		return std::make_shared<CWrapper>(sFileName);
	}
	
	static PWrapper loadLibraryFromSymbolLookupMethod(void* pSymbolLookupMethod)
	{
		return std::make_shared<CWrapper>(pSymbolLookupMethod);
	}
	
	~CWrapper()
	{
		releaseWrapperTable(&m_WrapperTable);
	}
	
	inline void CheckError(CBase * pBaseClass, RTTIResult nResult);

	inline void GetVersion(RTTI_uint32 & nMajor, RTTI_uint32 & nMinor, RTTI_uint32 & nMicro);
	inline bool GetLastError(classParam<CBase> pInstance, std::string & sErrorMessage);
	inline void ReleaseInstance(classParam<CBase> pInstance);
	inline void AcquireInstance(classParam<CBase> pInstance);
	inline void InjectComponent(const std::string & sNameSpace, const RTTI_pvoid pSymbolAddressMethod);
	inline RTTI_pvoid GetSymbolLookupMethod();
	inline bool ImplementsInterface(classParam<CBase> pObject, const std::string & sClassName);
	inline PZoo CreateZoo();

private:
	sRTTIDynamicWrapperTable m_WrapperTable;
	
	RTTIResult checkBinaryVersion()
	{
		RTTI_uint32 nMajor, nMinor, nMicro;
		GetVersion(nMajor, nMinor, nMicro);
		if ( (nMajor != RTTI_VERSION_MAJOR) || (nMinor < RTTI_VERSION_MINOR) ) {
			return RTTI_ERROR_INCOMPATIBLEBINARYVERSION;
		}
		return RTTI_SUCCESS;
	}
	RTTIResult initWrapperTable(sRTTIDynamicWrapperTable * pWrapperTable);
	RTTIResult releaseWrapperTable(sRTTIDynamicWrapperTable * pWrapperTable);
	RTTIResult loadWrapperTable(sRTTIDynamicWrapperTable * pWrapperTable, const char * pLibraryFileName);
	RTTIResult loadWrapperTableFromSymbolLookupMethod(sRTTIDynamicWrapperTable * pWrapperTable, void* pSymbolLookupMethod);

	friend class CBase;
	friend class CAnimal;
	friend class CMammal;
	friend class CReptile;
	friend class CGiraffe;
	friend class CTiger;
	friend class CSnake;
	friend class CTurtle;
	friend class CAnimalIterator;
	friend class CZoo;

};

	
/*************************************************************************************************************************
 Class CBase 
**************************************************************************************************************************/
class CBase {
public:
	static const std::string &getClassName();
protected:
	/* Wrapper Object that created the class. */
	CWrapper * m_pWrapper;
	/* Handle to Instance in library*/
	RTTIHandle m_pHandle;

	/* Checks for an Error code and raises Exceptions */
	void CheckError(RTTIResult nResult)
	{
		if (m_pWrapper != nullptr)
			m_pWrapper->CheckError(this, nResult);
	}
public:
	/**
	* CBase::CBase - Constructor for Base class.
	*/
	CBase(CWrapper * pWrapper, RTTIHandle pHandle)
		: m_pWrapper(pWrapper), m_pHandle(pHandle)
	{
	}

	/**
	* CBase::~CBase - Destructor for Base class.
	*/
	virtual ~CBase()
	{
		if (m_pWrapper != nullptr)
			m_pWrapper->ReleaseInstance(this);
		m_pWrapper = nullptr;
	}

	/**
	* CBase::handle - Returns handle to instance.
	*/
	RTTIHandle handle() const
	{
		return m_pHandle;
	}

	/**
	* CBase::wrapper - Returns wrapper instance.
	*/
	CWrapper * wrapper() const
	{
		return m_pWrapper;
	}
	
	friend class CWrapper;
	template <class T>
	friend std::shared_ptr<T> rtti_cast(PBase obj);
};
	
/*************************************************************************************************************************
 Class CAnimal 
**************************************************************************************************************************/
class CAnimal : public CBase {
public:
	static const std::string &getClassName();

	/**
	* CAnimal::CAnimal - Constructor for Animal class.
	*/
	CAnimal(CWrapper* pWrapper, RTTIHandle pHandle)
		: CBase(pWrapper, pHandle)
	{
	}
	
};
	
/*************************************************************************************************************************
 Class CMammal 
**************************************************************************************************************************/
class CMammal : public CAnimal {
public:
	static const std::string &getClassName();

	/**
	* CMammal::CMammal - Constructor for Mammal class.
	*/
	CMammal(CWrapper* pWrapper, RTTIHandle pHandle)
		: CAnimal(pWrapper, pHandle)
	{
	}
	
};
	
/*************************************************************************************************************************
 Class CReptile 
**************************************************************************************************************************/
class CReptile : public CAnimal {
public:
	static const std::string &getClassName();

	/**
	* CReptile::CReptile - Constructor for Reptile class.
	*/
	CReptile(CWrapper* pWrapper, RTTIHandle pHandle)
		: CAnimal(pWrapper, pHandle)
	{
	}
	
};
	
/*************************************************************************************************************************
 Class CGiraffe 
**************************************************************************************************************************/
class CGiraffe : public CMammal {
public:
	static const std::string &getClassName();

	/**
	* CGiraffe::CGiraffe - Constructor for Giraffe class.
	*/
	CGiraffe(CWrapper* pWrapper, RTTIHandle pHandle)
		: CMammal(pWrapper, pHandle)
	{
	}
	
};
	
/*************************************************************************************************************************
 Class CTiger 
**************************************************************************************************************************/
class CTiger : public CMammal {
public:
	static const std::string &getClassName();

	/**
	* CTiger::CTiger - Constructor for Tiger class.
	*/
	CTiger(CWrapper* pWrapper, RTTIHandle pHandle)
		: CMammal(pWrapper, pHandle)
	{
	}
	
	inline void Roar();
};
	
/*************************************************************************************************************************
 Class CSnake 
**************************************************************************************************************************/
class CSnake : public CReptile {
public:
	static const std::string &getClassName();

	/**
	* CSnake::CSnake - Constructor for Snake class.
	*/
	CSnake(CWrapper* pWrapper, RTTIHandle pHandle)
		: CReptile(pWrapper, pHandle)
	{
	}
	
};
	
/*************************************************************************************************************************
 Class CTurtle 
**************************************************************************************************************************/
class CTurtle : public CReptile {
public:
	static const std::string &getClassName();

	/**
	* CTurtle::CTurtle - Constructor for Turtle class.
	*/
	CTurtle(CWrapper* pWrapper, RTTIHandle pHandle)
		: CReptile(pWrapper, pHandle)
	{
	}
	
};
	
/*************************************************************************************************************************
 Class CAnimalIterator 
**************************************************************************************************************************/
class CAnimalIterator : public CBase {
public:
	static const std::string &getClassName();

	/**
	* CAnimalIterator::CAnimalIterator - Constructor for AnimalIterator class.
	*/
	CAnimalIterator(CWrapper* pWrapper, RTTIHandle pHandle)
		: CBase(pWrapper, pHandle)
	{
	}
	
	inline PAnimal GetNextAnimal();
};
	
/*************************************************************************************************************************
 Class CZoo 
**************************************************************************************************************************/
class CZoo : public CBase {
public:
	static const std::string &getClassName();

	/**
	* CZoo::CZoo - Constructor for Zoo class.
	*/
	CZoo(CWrapper* pWrapper, RTTIHandle pHandle)
		: CBase(pWrapper, pHandle)
	{
	}
	
	inline PAnimalIterator Iterator();
};

	const std::string &CBase::getClassName()
{
		static const std::string s_sClassName = "Base";
		return s_sClassName;
	}
	const std::string &CAnimal::getClassName()
        {
		static const std::string s_sClassName = "Animal";
		return s_sClassName;
	}
	const std::string &CMammal::getClassName()
        {
		static const std::string s_sClassName = "Mammal";
		return s_sClassName;
	}
	const std::string &CReptile::getClassName()
        {
		static const std::string s_sClassName = "Reptile";
		return s_sClassName;
	}
	const std::string &CGiraffe::getClassName()
        {
		static const std::string s_sClassName = "Giraffe";
		return s_sClassName;
	}
	const std::string &CTiger::getClassName()
        {
		static const std::string s_sClassName = "Tiger";
		return s_sClassName;
	}
	const std::string &CSnake::getClassName()
        {
		static const std::string s_sClassName = "Snake";
		return s_sClassName;
	}
	const std::string &CTurtle::getClassName()
        {
		static const std::string s_sClassName = "Turtle";
		return s_sClassName;
	}
	const std::string &CAnimalIterator::getClassName()
        {
		static const std::string s_sClassName = "AnimalIterator";
		return s_sClassName;
	}
	const std::string &CZoo::getClassName()
	{
		static const std::string s_sClassName = "Zoo";
		return s_sClassName;
	}

	template <class T>
	std::shared_ptr<T> rtti_cast(PBase pObj)
	{
		static_assert(std::is_convertible<T, CBase>::value, "T must be convertible to RTTI::CBase");

                if (pObj && pObj->m_pWrapper->ImplementsInterface(pObj.get(), T::getClassName())){
			return std::make_shared<T>(pObj->m_pWrapper, pObj->m_pHandle);
		}

		return nullptr;
	}

	/**
	* CWrapper::GetVersion - retrieves the binary version of this library.
	* @param[out] nMajor - returns the major version of this library
	* @param[out] nMinor - returns the minor version of this library
	* @param[out] nMicro - returns the micro version of this library
	*/
	inline void CWrapper::GetVersion(RTTI_uint32 & nMajor, RTTI_uint32 & nMinor, RTTI_uint32 & nMicro)
	{
		CheckError(nullptr,m_WrapperTable.m_GetVersion(&nMajor, &nMinor, &nMicro));
	}
	
	/**
	* CWrapper::GetLastError - Returns the last error recorded on this object
	* @param[in] pInstance - Instance Handle
	* @param[out] sErrorMessage - Message of the last error
	* @return Is there a last error to query
	*/
	inline bool CWrapper::GetLastError(classParam<CBase> pInstance, std::string & sErrorMessage)
	{
		RTTIHandle hInstance = pInstance.GetHandle();
		RTTI_uint32 bytesNeededErrorMessage = 0;
		RTTI_uint32 bytesWrittenErrorMessage = 0;
		bool resultHasError = 0;
		CheckError(nullptr,m_WrapperTable.m_GetLastError(hInstance, 0, &bytesNeededErrorMessage, nullptr, &resultHasError));
		std::vector<char> bufferErrorMessage(bytesNeededErrorMessage);
		CheckError(nullptr,m_WrapperTable.m_GetLastError(hInstance, bytesNeededErrorMessage, &bytesWrittenErrorMessage, &bufferErrorMessage[0], &resultHasError));
		sErrorMessage = std::string(&bufferErrorMessage[0]);
		
		return resultHasError;
	}
	
	/**
	* CWrapper::ReleaseInstance - Releases shared ownership of an Instance
	* @param[in] pInstance - Instance Handle
	*/
	inline void CWrapper::ReleaseInstance(classParam<CBase> pInstance)
	{
		RTTIHandle hInstance = pInstance.GetHandle();
		CheckError(nullptr,m_WrapperTable.m_ReleaseInstance(hInstance));
	}
	
	/**
	* CWrapper::AcquireInstance - Acquires shared ownership of an Instance
	* @param[in] pInstance - Instance Handle
	*/
	inline void CWrapper::AcquireInstance(classParam<CBase> pInstance)
	{
		RTTIHandle hInstance = pInstance.GetHandle();
		CheckError(nullptr,m_WrapperTable.m_AcquireInstance(hInstance));
	}
	
	/**
	* CWrapper::InjectComponent - Injects an imported component for usage within this component
	* @param[in] sNameSpace - NameSpace of the injected component
	* @param[in] pSymbolAddressMethod - Address of the SymbolAddressMethod of the injected component
	*/
	inline void CWrapper::InjectComponent(const std::string & sNameSpace, const RTTI_pvoid pSymbolAddressMethod)
	{
		CheckError(nullptr,m_WrapperTable.m_InjectComponent(sNameSpace.c_str(), pSymbolAddressMethod));
		
		bool bNameSpaceFound = false;
		if (!bNameSpaceFound)
			throw ERTTIException(RTTI_ERROR_COULDNOTLOADLIBRARY, "Unknown namespace " + sNameSpace);
	}
	
	/**
	* CWrapper::GetSymbolLookupMethod - Returns the address of the SymbolLookupMethod
	* @return Address of the SymbolAddressMethod
	*/
	inline RTTI_pvoid CWrapper::GetSymbolLookupMethod()
	{
		RTTI_pvoid resultSymbolLookupMethod = 0;
		CheckError(nullptr,m_WrapperTable.m_GetSymbolLookupMethod(&resultSymbolLookupMethod));
		
		return resultSymbolLookupMethod;
	}
	
	/**
	* CWrapper::ImplementsInterface - Test whether an object implements a given interface
	* @param[in] pObject - Instance Handle
	* @param[in] sClassName - Class name of the interface to test
	* @return Will be set to true if pInstance implements the interface, false otherwise
	*/
	inline bool CWrapper::ImplementsInterface(classParam<CBase> pObject, const std::string & sClassName)
	{
		RTTIHandle hObject = pObject.GetHandle();
		bool resultImplementsInterface = 0;
		CheckError(nullptr,m_WrapperTable.m_ImplementsInterface(hObject, sClassName.c_str(), &resultImplementsInterface));
		
		return resultImplementsInterface;
	}
	
	/**
	* CWrapper::CreateZoo - Create a new zoo with animals
	* @return 
	*/
	inline PZoo CWrapper::CreateZoo()
	{
		RTTIHandle hInstance = nullptr;
		CheckError(nullptr,m_WrapperTable.m_CreateZoo(&hInstance));
		
		if (!hInstance) {
			CheckError(nullptr,RTTI_ERROR_INVALIDPARAM);
		}
		return std::make_shared<CZoo>(this, hInstance);
	}
	
	inline void CWrapper::CheckError(CBase * pBaseClass, RTTIResult nResult)
	{
		if (nResult != 0) {
			std::string sErrorMessage;
			if (pBaseClass != nullptr) {
				GetLastError(pBaseClass, sErrorMessage);
			}
			throw ERTTIException(nResult, sErrorMessage);
		}
	}


	inline RTTIResult CWrapper::initWrapperTable(sRTTIDynamicWrapperTable * pWrapperTable)
	{
		if (pWrapperTable == nullptr)
			return RTTI_ERROR_INVALIDPARAM;
		
		pWrapperTable->m_LibraryHandle = nullptr;
		pWrapperTable->m_Tiger_Roar = nullptr;
		pWrapperTable->m_AnimalIterator_GetNextAnimal = nullptr;
		pWrapperTable->m_Zoo_Iterator = nullptr;
		pWrapperTable->m_GetVersion = nullptr;
		pWrapperTable->m_GetLastError = nullptr;
		pWrapperTable->m_ReleaseInstance = nullptr;
		pWrapperTable->m_AcquireInstance = nullptr;
		pWrapperTable->m_InjectComponent = nullptr;
		pWrapperTable->m_GetSymbolLookupMethod = nullptr;
		pWrapperTable->m_ImplementsInterface = nullptr;
		pWrapperTable->m_CreateZoo = nullptr;
		
		return RTTI_SUCCESS;
	}

	inline RTTIResult CWrapper::releaseWrapperTable(sRTTIDynamicWrapperTable * pWrapperTable)
	{
		if (pWrapperTable == nullptr)
			return RTTI_ERROR_INVALIDPARAM;
		
		if (pWrapperTable->m_LibraryHandle != nullptr) {
		#ifdef _WIN32
			HMODULE hModule = (HMODULE) pWrapperTable->m_LibraryHandle;
			FreeLibrary(hModule);
		#else // _WIN32
			dlclose(pWrapperTable->m_LibraryHandle);
		#endif // _WIN32
			return initWrapperTable(pWrapperTable);
		}
		
		return RTTI_SUCCESS;
	}

	inline RTTIResult CWrapper::loadWrapperTable(sRTTIDynamicWrapperTable * pWrapperTable, const char * pLibraryFileName)
	{
		if (pWrapperTable == nullptr)
			return RTTI_ERROR_INVALIDPARAM;
		if (pLibraryFileName == nullptr)
			return RTTI_ERROR_INVALIDPARAM;
		
		#ifdef _WIN32
		// Convert filename to UTF16-string
		int nLength = (int)strlen(pLibraryFileName);
		int nBufferSize = nLength * 2 + 2;
		std::vector<wchar_t> wsLibraryFileName(nBufferSize);
		int nResult = MultiByteToWideChar(CP_UTF8, 0, pLibraryFileName, nLength, &wsLibraryFileName[0], nBufferSize);
		if (nResult == 0)
			return RTTI_ERROR_COULDNOTLOADLIBRARY;
		
		HMODULE hLibrary = LoadLibraryW(wsLibraryFileName.data());
		if (hLibrary == 0) 
			return RTTI_ERROR_COULDNOTLOADLIBRARY;
		#else // _WIN32
		void* hLibrary = dlopen(pLibraryFileName, RTLD_LAZY);
		if (hLibrary == 0) 
			return RTTI_ERROR_COULDNOTLOADLIBRARY;
		dlerror();
		#endif // _WIN32
		
		#ifdef _WIN32
		pWrapperTable->m_Tiger_Roar = (PRTTITiger_RoarPtr) GetProcAddress(hLibrary, "rtti_tiger_roar");
		#else // _WIN32
		pWrapperTable->m_Tiger_Roar = (PRTTITiger_RoarPtr) dlsym(hLibrary, "rtti_tiger_roar");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_Tiger_Roar == nullptr)
			return RTTI_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_AnimalIterator_GetNextAnimal = (PRTTIAnimalIterator_GetNextAnimalPtr) GetProcAddress(hLibrary, "rtti_animaliterator_getnextanimal");
		#else // _WIN32
		pWrapperTable->m_AnimalIterator_GetNextAnimal = (PRTTIAnimalIterator_GetNextAnimalPtr) dlsym(hLibrary, "rtti_animaliterator_getnextanimal");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_AnimalIterator_GetNextAnimal == nullptr)
			return RTTI_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_Zoo_Iterator = (PRTTIZoo_IteratorPtr) GetProcAddress(hLibrary, "rtti_zoo_iterator");
		#else // _WIN32
		pWrapperTable->m_Zoo_Iterator = (PRTTIZoo_IteratorPtr) dlsym(hLibrary, "rtti_zoo_iterator");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_Zoo_Iterator == nullptr)
			return RTTI_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_GetVersion = (PRTTIGetVersionPtr) GetProcAddress(hLibrary, "rtti_getversion");
		#else // _WIN32
		pWrapperTable->m_GetVersion = (PRTTIGetVersionPtr) dlsym(hLibrary, "rtti_getversion");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_GetVersion == nullptr)
			return RTTI_ERROR_COULDNOTFINDLIBRARYEXPORT;

		#ifdef _WIN32
		pWrapperTable->m_GetLastError = (PRTTIGetLastErrorPtr) GetProcAddress(hLibrary, "rtti_getlasterror");
		#else // _WIN32
		pWrapperTable->m_GetLastError = (PRTTIGetLastErrorPtr) dlsym(hLibrary, "rtti_getlasterror");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_GetLastError == nullptr)
			return RTTI_ERROR_COULDNOTFINDLIBRARYEXPORT;

		#ifdef _WIN32
		pWrapperTable->m_ReleaseInstance = (PRTTIReleaseInstancePtr) GetProcAddress(hLibrary, "rtti_releaseinstance");
		#else // _WIN32
		pWrapperTable->m_ReleaseInstance = (PRTTIReleaseInstancePtr) dlsym(hLibrary, "rtti_releaseinstance");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_ReleaseInstance == nullptr)
			return RTTI_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_AcquireInstance = (PRTTIAcquireInstancePtr) GetProcAddress(hLibrary, "rtti_acquireinstance");
		#else // _WIN32
		pWrapperTable->m_AcquireInstance = (PRTTIAcquireInstancePtr) dlsym(hLibrary, "rtti_acquireinstance");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_AcquireInstance == nullptr)
			return RTTI_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_InjectComponent = (PRTTIInjectComponentPtr) GetProcAddress(hLibrary, "rtti_injectcomponent");
		#else // _WIN32
		pWrapperTable->m_InjectComponent = (PRTTIInjectComponentPtr) dlsym(hLibrary, "rtti_injectcomponent");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_InjectComponent == nullptr)
			return RTTI_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_GetSymbolLookupMethod = (PRTTIGetSymbolLookupMethodPtr) GetProcAddress(hLibrary, "rtti_getsymbollookupmethod");
		#else // _WIN32
		pWrapperTable->m_GetSymbolLookupMethod = (PRTTIGetSymbolLookupMethodPtr) dlsym(hLibrary, "rtti_getsymbollookupmethod");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_GetSymbolLookupMethod == nullptr)
			return RTTI_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_ImplementsInterface = (PRTTIImplementsInterfacePtr) GetProcAddress(hLibrary, "rtti_implementsinterface");
		#else // _WIN32
		pWrapperTable->m_ImplementsInterface = (PRTTIImplementsInterfacePtr) dlsym(hLibrary, "rtti_implementsinterface");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_ImplementsInterface == nullptr)
			return RTTI_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		#ifdef _WIN32
		pWrapperTable->m_CreateZoo = (PRTTICreateZooPtr) GetProcAddress(hLibrary, "rtti_createzoo");
		#else // _WIN32
		pWrapperTable->m_CreateZoo = (PRTTICreateZooPtr) dlsym(hLibrary, "rtti_createzoo");
		dlerror();
		#endif // _WIN32
		if (pWrapperTable->m_CreateZoo == nullptr)
			return RTTI_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		pWrapperTable->m_LibraryHandle = hLibrary;
		return RTTI_SUCCESS;
	}

	inline RTTIResult CWrapper::loadWrapperTableFromSymbolLookupMethod(sRTTIDynamicWrapperTable * pWrapperTable, void* pSymbolLookupMethod)
{
		if (pWrapperTable == nullptr)
			return RTTI_ERROR_INVALIDPARAM;
		if (pSymbolLookupMethod == nullptr)
			return RTTI_ERROR_INVALIDPARAM;
		
		typedef RTTIResult(*SymbolLookupType)(const char*, void**);
		
		SymbolLookupType pLookup = (SymbolLookupType)pSymbolLookupMethod;
		
		RTTIResult eLookupError = RTTI_SUCCESS;
		eLookupError = (*pLookup)("rtti_tiger_roar", (void**)&(pWrapperTable->m_Tiger_Roar));
		if ( (eLookupError != 0) || (pWrapperTable->m_Tiger_Roar == nullptr) )
			return RTTI_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("rtti_animaliterator_getnextanimal", (void**)&(pWrapperTable->m_AnimalIterator_GetNextAnimal));
		if ( (eLookupError != 0) || (pWrapperTable->m_AnimalIterator_GetNextAnimal == nullptr) )
			return RTTI_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("rtti_zoo_iterator", (void**)&(pWrapperTable->m_Zoo_Iterator));
		if ( (eLookupError != 0) || (pWrapperTable->m_Zoo_Iterator == nullptr) )
			return RTTI_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("rtti_getversion", (void**)&(pWrapperTable->m_GetVersion));
		if ( (eLookupError != 0) || (pWrapperTable->m_GetVersion == nullptr) )
			return RTTI_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("rtti_getlasterror", (void**)&(pWrapperTable->m_GetLastError));
		if ( (eLookupError != 0) || (pWrapperTable->m_GetLastError == nullptr) )
			return RTTI_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("rtti_releaseinstance", (void**)&(pWrapperTable->m_ReleaseInstance));
		if ( (eLookupError != 0) || (pWrapperTable->m_ReleaseInstance == nullptr) )
			return RTTI_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("rtti_acquireinstance", (void**)&(pWrapperTable->m_AcquireInstance));
		if ( (eLookupError != 0) || (pWrapperTable->m_AcquireInstance == nullptr) )
			return RTTI_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("rtti_injectcomponent", (void**)&(pWrapperTable->m_InjectComponent));
		if ( (eLookupError != 0) || (pWrapperTable->m_InjectComponent == nullptr) )
			return RTTI_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("rtti_getsymbollookupmethod", (void**)&(pWrapperTable->m_GetSymbolLookupMethod));
		if ( (eLookupError != 0) || (pWrapperTable->m_GetSymbolLookupMethod == nullptr) )
			return RTTI_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("rtti_implementsinterface", (void**)&(pWrapperTable->m_ImplementsInterface));
		if ( (eLookupError != 0) || (pWrapperTable->m_ImplementsInterface == nullptr) )
			return RTTI_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		eLookupError = (*pLookup)("rtti_createzoo", (void**)&(pWrapperTable->m_CreateZoo));
		if ( (eLookupError != 0) || (pWrapperTable->m_CreateZoo == nullptr) )
			return RTTI_ERROR_COULDNOTFINDLIBRARYEXPORT;
		
		return RTTI_SUCCESS;
}

	
	
	/**
	 * Method definitions for class CBase
	 */
	
	/**
	 * Method definitions for class CAnimal
	 */
	
	/**
	 * Method definitions for class CMammal
	 */
	
	/**
	 * Method definitions for class CReptile
	 */
	
	/**
	 * Method definitions for class CGiraffe
	 */
	
	/**
	 * Method definitions for class CTiger
	 */
	
	/**
	* CTiger::Roar - Roar like a tiger
	*/
	void CTiger::Roar()
	{
		CheckError(m_pWrapper->m_WrapperTable.m_Tiger_Roar(m_pHandle));
	}
	
	/**
	 * Method definitions for class CSnake
	 */
	
	/**
	 * Method definitions for class CTurtle
	 */
	
	/**
	 * Method definitions for class CAnimalIterator
	 */
	
	/**
	* CAnimalIterator::GetNextAnimal - Return next animal
	* @return 
	*/
	PAnimal CAnimalIterator::GetNextAnimal()
	{
		RTTIHandle hAnimal = nullptr;
		CheckError(m_pWrapper->m_WrapperTable.m_AnimalIterator_GetNextAnimal(m_pHandle, &hAnimal));
		
		if (hAnimal) {
			return std::make_shared<CAnimal>(m_pWrapper, hAnimal);
		} else {
			return nullptr;
		}
	}
	
	/**
	 * Method definitions for class CZoo
	 */
	
	/**
	* CZoo::Iterator - Return an iterator over all zoo animals
	* @return 
	*/
	PAnimalIterator CZoo::Iterator()
	{
		RTTIHandle hIterator = nullptr;
		CheckError(m_pWrapper->m_WrapperTable.m_Zoo_Iterator(m_pHandle, &hIterator));
		
		if (!hIterator) {
			CheckError(RTTI_ERROR_INVALIDPARAM);
		}
		return std::make_shared<CAnimalIterator>(m_pWrapper, hIterator);
	}

} // namespace RTTI

#endif // __RTTI_CPPHEADER_DYNAMIC_CPP

