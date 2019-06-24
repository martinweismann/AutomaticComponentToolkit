'''++

Copyright (C) 2019 Calculation developers

All rights reserved.

This file has been generated by the Automatic Component Toolkit (ACT) version 1.6.0-develop.

Abstract: This is an autogenerated Python file in order to allow an easy
 use of Calculation library

Interface version: 1.0.0

'''


import ctypes
import platform
import enum
import os

import sys
# Injected Components
sys.path.append(os.path.join(os.path.dirname(os.path.realpath(__file__)), "..", "..", "..", "Numbers_component", "Bindings", "Python"))
import Numbers

name = "calculation"

'''Definition of domain specific exception
'''
class ECalculationException(Exception):
	def __init__(self, code, message = ''):
		self._code = code
		self._message = message
	
	def __str__(self):
		if self._message:
			return 'CalculationException ' + str(self._code) + ': '+ str(self._message)
		return 'CalculationException ' + str(self._code)

'''Definition of binding API version
'''
class BindingVersion(enum.IntEnum):
	MAJOR = 1
	MINOR = 0
	MICRO = 0

'''Definition Error Codes
'''
class ErrorCodes(enum.IntEnum):
	SUCCESS = 0
	NOTIMPLEMENTED = 1
	INVALIDPARAM = 2
	INVALIDCAST = 3
	BUFFERTOOSMALL = 4
	GENERICEXCEPTION = 5
	COULDNOTLOADLIBRARY = 6
	COULDNOTFINDLIBRARYEXPORT = 7
	INCOMPATIBLEBINARYVERSION = 8

'''Definition of Function Table
'''
class FunctionTable:
	calculation_createcalculator = None
	calculation_getversion = None
	calculation_getlasterror = None
	calculation_releaseinstance = None
	calculation_acquireinstance = None
	calculation_injectcomponent = None
	calculation_getsymbollookupmethod = None
	calculation_calculator_enlistvariable = None
	calculation_calculator_getenlistedvariable = None
	calculation_calculator_clearvariables = None
	calculation_calculator_multiply = None
	calculation_calculator_add = None


'''Wrapper Class Implementation
'''
class Wrapper:

# Injected Components
	_NumbersWrapper = None

	def __init__(self, libraryName = None, symbolLookupMethodAddress = None):
		ending = ''
		if platform.system() == 'Windows':
			ending = 'dll'
		elif platform.system() == 'Linux':
			ending = 'so'
		elif platform.system() == 'Darwin':
			ending = 'dylib'
		else:
			raise ECalculationException(ErrorCodes.COULDNOTLOADLIBRARY)
		
		if (not libraryName) and (not symbolLookupMethodAddress):
			libraryName = os.path.join(os.path.dirname(os.path.realpath(__file__)),'calculation')
		
		if libraryName is not None:
			path = libraryName + '.' + ending
			try:
				self.lib = ctypes.CDLL(path)
			except Exception as e:
				raise ECalculationException(ErrorCodes.COULDNOTLOADLIBRARY, str(e) + '| "'+path + '"' )
			
			self._loadFunctionTable()
		elif symbolLookupMethodAddress is not None:
				self.lib = FunctionTable()
				self._loadFunctionTableFromMethod(symbolLookupMethodAddress)
		else:
			raise ECalculationException(ErrorCodes.COULDNOTLOADLIBRARY, str(e))
		
		self._checkBinaryVersion()
	
	def _loadFunctionTableFromMethod(self, symbolLookupMethodAddress):
		try:
			symbolLookupMethodType = ctypes.CFUNCTYPE(ctypes.c_int32, ctypes.c_char_p, ctypes.POINTER(ctypes.c_void_p))
			symbolLookupMethod = symbolLookupMethodType(int(symbolLookupMethodAddress))
			
			methodAddress = ctypes.c_void_p()
			
			err = symbolLookupMethod(ctypes.c_char_p(str.encode("calculation_createcalculator")), methodAddress)
			if err != 0:
				raise ECalculationException(ErrorCodes.COULDNOTLOADLIBRARY, str(err))
			methodType = ctypes.CFUNCTYPE(ctypes.c_int32, ctypes.POINTER(ctypes.c_void_p))
			self.lib.calculation_createcalculator = methodType(int(methodAddress.value))
			
			err = symbolLookupMethod(ctypes.c_char_p(str.encode("calculation_getversion")), methodAddress)
			if err != 0:
				raise ECalculationException(ErrorCodes.COULDNOTLOADLIBRARY, str(err))
			methodType = ctypes.CFUNCTYPE(ctypes.c_int32, ctypes.POINTER(ctypes.c_uint32), ctypes.POINTER(ctypes.c_uint32), ctypes.POINTER(ctypes.c_uint32))
			self.lib.calculation_getversion = methodType(int(methodAddress.value))
			
			err = symbolLookupMethod(ctypes.c_char_p(str.encode("calculation_getlasterror")), methodAddress)
			if err != 0:
				raise ECalculationException(ErrorCodes.COULDNOTLOADLIBRARY, str(err))
			methodType = ctypes.CFUNCTYPE(ctypes.c_int32, ctypes.c_void_p, ctypes.c_uint64, ctypes.POINTER(ctypes.c_uint64), ctypes.c_char_p, ctypes.POINTER(ctypes.c_bool))
			self.lib.calculation_getlasterror = methodType(int(methodAddress.value))
			
			err = symbolLookupMethod(ctypes.c_char_p(str.encode("calculation_releaseinstance")), methodAddress)
			if err != 0:
				raise ECalculationException(ErrorCodes.COULDNOTLOADLIBRARY, str(err))
			methodType = ctypes.CFUNCTYPE(ctypes.c_int32, ctypes.c_void_p)
			self.lib.calculation_releaseinstance = methodType(int(methodAddress.value))
			
			err = symbolLookupMethod(ctypes.c_char_p(str.encode("calculation_acquireinstance")), methodAddress)
			if err != 0:
				raise ECalculationException(ErrorCodes.COULDNOTLOADLIBRARY, str(err))
			methodType = ctypes.CFUNCTYPE(ctypes.c_int32, ctypes.c_void_p)
			self.lib.calculation_acquireinstance = methodType(int(methodAddress.value))
			
			err = symbolLookupMethod(ctypes.c_char_p(str.encode("calculation_injectcomponent")), methodAddress)
			if err != 0:
				raise ECalculationException(ErrorCodes.COULDNOTLOADLIBRARY, str(err))
			methodType = ctypes.CFUNCTYPE(ctypes.c_int32, ctypes.c_char_p, ctypes.c_void_p)
			self.lib.calculation_injectcomponent = methodType(int(methodAddress.value))
			
			err = symbolLookupMethod(ctypes.c_char_p(str.encode("calculation_getsymbollookupmethod")), methodAddress)
			if err != 0:
				raise ECalculationException(ErrorCodes.COULDNOTLOADLIBRARY, str(err))
			methodType = ctypes.CFUNCTYPE(ctypes.c_int32, ctypes.POINTER(ctypes.c_void_p))
			self.lib.calculation_getsymbollookupmethod = methodType(int(methodAddress.value))
			
			err = symbolLookupMethod(ctypes.c_char_p(str.encode("calculation_calculator_enlistvariable")), methodAddress)
			if err != 0:
				raise ECalculationException(ErrorCodes.COULDNOTLOADLIBRARY, str(err))
			methodType = ctypes.CFUNCTYPE(ctypes.c_int32, ctypes.c_void_p, ctypes.c_void_p)
			self.lib.calculation_calculator_enlistvariable = methodType(int(methodAddress.value))
			
			err = symbolLookupMethod(ctypes.c_char_p(str.encode("calculation_calculator_getenlistedvariable")), methodAddress)
			if err != 0:
				raise ECalculationException(ErrorCodes.COULDNOTLOADLIBRARY, str(err))
			methodType = ctypes.CFUNCTYPE(ctypes.c_int32, ctypes.c_void_p, ctypes.c_uint32, ctypes.POINTER(ctypes.c_void_p))
			self.lib.calculation_calculator_getenlistedvariable = methodType(int(methodAddress.value))
			
			err = symbolLookupMethod(ctypes.c_char_p(str.encode("calculation_calculator_clearvariables")), methodAddress)
			if err != 0:
				raise ECalculationException(ErrorCodes.COULDNOTLOADLIBRARY, str(err))
			methodType = ctypes.CFUNCTYPE(ctypes.c_int32, ctypes.c_void_p)
			self.lib.calculation_calculator_clearvariables = methodType(int(methodAddress.value))
			
			err = symbolLookupMethod(ctypes.c_char_p(str.encode("calculation_calculator_multiply")), methodAddress)
			if err != 0:
				raise ECalculationException(ErrorCodes.COULDNOTLOADLIBRARY, str(err))
			methodType = ctypes.CFUNCTYPE(ctypes.c_int32, ctypes.c_void_p, ctypes.POINTER(ctypes.c_void_p))
			self.lib.calculation_calculator_multiply = methodType(int(methodAddress.value))
			
			err = symbolLookupMethod(ctypes.c_char_p(str.encode("calculation_calculator_add")), methodAddress)
			if err != 0:
				raise ECalculationException(ErrorCodes.COULDNOTLOADLIBRARY, str(err))
			methodType = ctypes.CFUNCTYPE(ctypes.c_int32, ctypes.c_void_p, ctypes.POINTER(ctypes.c_void_p))
			self.lib.calculation_calculator_add = methodType(int(methodAddress.value))
			
		except AttributeError as ae:
			raise ECalculationException(ErrorCodes.COULDNOTFINDLIBRARYEXPORT, ae.args[0])
		
	def _loadFunctionTable(self):
		try:
			self.lib.calculation_createcalculator.restype = ctypes.c_int32
			self.lib.calculation_createcalculator.argtypes = [ctypes.POINTER(ctypes.c_void_p)]
			
			self.lib.calculation_getversion.restype = ctypes.c_int32
			self.lib.calculation_getversion.argtypes = [ctypes.POINTER(ctypes.c_uint32), ctypes.POINTER(ctypes.c_uint32), ctypes.POINTER(ctypes.c_uint32)]
			
			self.lib.calculation_getlasterror.restype = ctypes.c_int32
			self.lib.calculation_getlasterror.argtypes = [ctypes.c_void_p, ctypes.c_uint64, ctypes.POINTER(ctypes.c_uint64), ctypes.c_char_p, ctypes.POINTER(ctypes.c_bool)]
			
			self.lib.calculation_releaseinstance.restype = ctypes.c_int32
			self.lib.calculation_releaseinstance.argtypes = [ctypes.c_void_p]
			
			self.lib.calculation_acquireinstance.restype = ctypes.c_int32
			self.lib.calculation_acquireinstance.argtypes = [ctypes.c_void_p]
			
			self.lib.calculation_injectcomponent.restype = ctypes.c_int32
			self.lib.calculation_injectcomponent.argtypes = [ctypes.c_char_p, ctypes.c_void_p]
			
			self.lib.calculation_getsymbollookupmethod.restype = ctypes.c_int32
			self.lib.calculation_getsymbollookupmethod.argtypes = [ctypes.POINTER(ctypes.c_void_p)]
			
			self.lib.calculation_calculator_enlistvariable.restype = ctypes.c_int32
			self.lib.calculation_calculator_enlistvariable.argtypes = [ctypes.c_void_p, ctypes.c_void_p]
			
			self.lib.calculation_calculator_getenlistedvariable.restype = ctypes.c_int32
			self.lib.calculation_calculator_getenlistedvariable.argtypes = [ctypes.c_void_p, ctypes.c_uint32, ctypes.POINTER(ctypes.c_void_p)]
			
			self.lib.calculation_calculator_clearvariables.restype = ctypes.c_int32
			self.lib.calculation_calculator_clearvariables.argtypes = [ctypes.c_void_p]
			
			self.lib.calculation_calculator_multiply.restype = ctypes.c_int32
			self.lib.calculation_calculator_multiply.argtypes = [ctypes.c_void_p, ctypes.POINTER(ctypes.c_void_p)]
			
			self.lib.calculation_calculator_add.restype = ctypes.c_int32
			self.lib.calculation_calculator_add.argtypes = [ctypes.c_void_p, ctypes.POINTER(ctypes.c_void_p)]
			
		except AttributeError as ae:
			raise ECalculationException(ErrorCodes.COULDNOTFINDLIBRARYEXPORT, ae.args[0])
	
	def _checkBinaryVersion(self):
		nMajor, nMinor, _ = self.GetVersion()
		if (nMajor != BindingVersion.MAJOR) or (nMinor < BindingVersion.MINOR):
			raise ECalculationException(ErrorCodes.INCOMPATIBLEBINARYVERSION)
	
	def checkError(self, instance, errorCode):
		if errorCode != ErrorCodes.SUCCESS.value:
			if instance:
				if instance._wrapper != self:
					raise ECalculationException(ErrorCodes.INVALIDCAST, 'invalid wrapper call')
			message,_ = self.GetLastError(instance)
			raise ECalculationException(errorCode, message)
	
	def CreateCalculator(self):
		InstanceHandle = ctypes.c_void_p()
		self.checkError(None, self.lib.calculation_createcalculator(InstanceHandle))
		InstanceObject = Calculator(InstanceHandle, self)
		
		return InstanceObject
	
	def GetVersion(self):
		pMajor = ctypes.c_uint32()
		pMinor = ctypes.c_uint32()
		pMicro = ctypes.c_uint32()
		self.checkError(None, self.lib.calculation_getversion(pMajor, pMinor, pMicro))
		
		return pMajor.value, pMinor.value, pMicro.value
	
	def GetLastError(self, InstanceObject):
		nErrorMessageBufferSize = ctypes.c_uint64(0)
		nErrorMessageNeededChars = ctypes.c_uint64(0)
		pErrorMessageBuffer = ctypes.c_char_p(None)
		pHasError = ctypes.c_bool()
		self.checkError(None, self.lib.calculation_getlasterror(InstanceObject._handle, nErrorMessageBufferSize, nErrorMessageNeededChars, pErrorMessageBuffer, pHasError))
		nErrorMessageBufferSize = ctypes.c_uint64(nErrorMessageNeededChars.value)
		pErrorMessageBuffer = (ctypes.c_char * (nErrorMessageNeededChars.value))()
		self.checkError(None, self.lib.calculation_getlasterror(InstanceObject._handle, nErrorMessageBufferSize, nErrorMessageNeededChars, pErrorMessageBuffer, pHasError))
		
		return pErrorMessageBuffer.value.decode(), pHasError.value
	
	def ReleaseInstance(self, InstanceObject):
		self.checkError(None, self.lib.calculation_releaseinstance(InstanceObject._handle))
		
	
	def AcquireInstance(self, InstanceObject):
		self.checkError(None, self.lib.calculation_acquireinstance(InstanceObject._handle))
		
	
	def InjectComponent(self, NameSpace, SymbolAddressMethod):
		pNameSpace = ctypes.c_char_p(str.encode(NameSpace))
		pSymbolAddressMethod = ctypes.c_void_p(SymbolAddressMethod)
		self.checkError(None, self.lib.calculation_injectcomponent(pNameSpace, pSymbolAddressMethod))
		
		bNameSpaceFound = False
		if NameSpace == "Numbers":
			if self._NumbersWrapper is not None:
				raise ECalculationException(ErrorCodes.COULDNOTLOADLIBRARY, "Library with namespace " + NameSpace + " is already registered.")
			self._NumbersWrapper = Numbers.Wrapper(symbolLookupMethodAddress = SymbolAddressMethod)
			bNameSpaceFound = True
		if not bNameSpaceFound:
			raise ECalculationException(ErrorCodes.COULDNOTLOADLIBRARY, "Unknown namespace " + NameSpace)
		
	
	def GetSymbolLookupMethod(self):
		pSymbolLookupMethod = ctypes.c_void_p()
		self.checkError(None, self.lib.calculation_getsymbollookupmethod(pSymbolLookupMethod))
		
		return pSymbolLookupMethod.value
	


''' Class Implementation for Base
'''
class Base:
	def __init__(self, handle, wrapper):
		if not handle or not wrapper:
			raise ECalculationException(ErrorCodes.INVALIDPARAM)
		self._handle = handle
		self._wrapper = wrapper
	
	def __del__(self):
		self._wrapper.ReleaseInstance(self)


''' Class Implementation for Calculator
'''
class Calculator(Base):
	def __init__(self, handle, wrapper):
		Base.__init__(self, handle, wrapper)
	def EnlistVariable(self, VariableObject):
		self._wrapper.checkError(self, self._wrapper.lib.calculation_calculator_enlistvariable(self._handle, VariableObject._handle))
		
	
	def GetEnlistedVariable(self, Index):
		nIndex = ctypes.c_uint32(Index)
		VariableHandle = ctypes.c_void_p()
		self._wrapper.checkError(self, self._wrapper.lib.calculation_calculator_getenlistedvariable(self._handle, nIndex, VariableHandle))
		VariableObject = Numbers.Variable(VariableHandle, self._wrapper._NumbersWrapper)
		
		return VariableObject
	
	def ClearVariables(self):
		self._wrapper.checkError(self, self._wrapper.lib.calculation_calculator_clearvariables(self._handle))
		
	
	def Multiply(self):
		InstanceHandle = ctypes.c_void_p()
		self._wrapper.checkError(self, self._wrapper.lib.calculation_calculator_multiply(self._handle, InstanceHandle))
		InstanceObject = Numbers.Variable(InstanceHandle, self._wrapper._NumbersWrapper)
		
		return InstanceObject
	
	def Add(self):
		InstanceHandle = ctypes.c_void_p()
		self._wrapper.checkError(self, self._wrapper.lib.calculation_calculator_add(self._handle, InstanceHandle))
		InstanceObject = Numbers.Variable(InstanceHandle, self._wrapper._NumbersWrapper)
		
		return InstanceObject
	
		
