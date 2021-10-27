{$IFDEF FPC}{$MODE DELPHI}{$ENDIF}
(*++

Copyright (C) 2019 Numbers developers

All rights reserved.

This file has been generated by the Automatic Component Toolkit (ACT) version 1.7.0-develop.

Abstract: This is an autogenerated Pascal Header file in order to allow an easy
 use of Numbers library

Interface version: 1.0.0

*)

unit Unit_Numbers;

interface

uses
  {$IFDEF WINDOWS}
    Windows,
  {$ELSE}
    dynlibs,
  {$ENDIF}
  Types,
  Classes,
  SysUtils;

(*************************************************************************************************************************
 Version definition for Numbers
**************************************************************************************************************************)

const
  NUMBERS_VERSION_MAJOR = 1;
  NUMBERS_VERSION_MINOR = 0;
  NUMBERS_VERSION_MICRO = 0;
  NUMBERS_VERSION_PRERELEASEINFO = '';
  NUMBERS_VERSION_BUILDINFO = '';


(*************************************************************************************************************************
 General type definitions
**************************************************************************************************************************)

type
  TNumbersResult = Cardinal;
  TNumbersHandle = packed record
  	Handle: Pointer;
  	ClassTypeId: QWord;
  end;

  PNumbersResult = ^TNumbersResult;
  PNumbersHandle = ^TNumbersHandle;

(*************************************************************************************************************************
 Error Constants for Numbers
**************************************************************************************************************************)

const
  NUMBERS_SUCCESS = 0;
  NUMBERS_ERROR_NOTIMPLEMENTED = 1;
  NUMBERS_ERROR_INVALIDPARAM = 2;
  NUMBERS_ERROR_INVALIDCAST = 3;
  NUMBERS_ERROR_BUFFERTOOSMALL = 4;
  NUMBERS_ERROR_GENERICEXCEPTION = 5;
  NUMBERS_ERROR_COULDNOTLOADLIBRARY = 6;
  NUMBERS_ERROR_COULDNOTFINDLIBRARYEXPORT = 7;
  NUMBERS_ERROR_INCOMPATIBLEBINARYVERSION = 8;


(*************************************************************************************************************************
 Declaration of handle classes 
**************************************************************************************************************************)

type
  TNumbersWrapper = class;
  TNumbersBase = class;
  TNumbersVariable = class;


(*************************************************************************************************************************
 Function type definitions for Base
**************************************************************************************************************************)

  (**
  * Get Class Type Id
  *
  * @param[in] pBase - Base instance.
  * @param[out] pClassTypeId - Class type as a 64 bits integer
  * @return error code or 0 (success)
  *)
  TNumbersBase_ClassTypeIdFunc = function(pBase: TNumbersHandle; out pClassTypeId: QWord): TNumbersResult; cdecl;
  

(*************************************************************************************************************************
 Function type definitions for Variable
**************************************************************************************************************************)

  (**
  * Returns the current value of this Variable
  *
  * @param[in] pVariable - Variable instance.
  * @param[out] pValue - The current value of this Variable
  * @return error code or 0 (success)
  *)
  TNumbersVariable_GetValueFunc = function(pVariable: TNumbersHandle; out pValue: Double): TNumbersResult; cdecl;
  
  (**
  * Set the numerical value of this Variable
  *
  * @param[in] pVariable - Variable instance.
  * @param[in] dValue - The new value of this Variable
  * @return error code or 0 (success)
  *)
  TNumbersVariable_SetValueFunc = function(pVariable: TNumbersHandle; const dValue: Double): TNumbersResult; cdecl;
  
(*************************************************************************************************************************
 Global function definitions 
**************************************************************************************************************************)

  (**
  * Creates a new Variable instance
  *
  * @param[in] dInitialValue - Initial value of the new Variable
  * @param[out] pInstance - New Variable instance
  * @return error code or 0 (success)
  *)
  TNumbersCreateVariableFunc = function(const dInitialValue: Double; out pInstance: TNumbersHandle): TNumbersResult; cdecl;
  
  (**
  * retrieves the binary version of this library.
  *
  * @param[out] pMajor - returns the major version of this library
  * @param[out] pMinor - returns the minor version of this library
  * @param[out] pMicro - returns the micro version of this library
  * @return error code or 0 (success)
  *)
  TNumbersGetVersionFunc = function(out pMajor: Cardinal; out pMinor: Cardinal; out pMicro: Cardinal): TNumbersResult; cdecl;
  
  (**
  * Returns the last error recorded on this object
  *
  * @param[in] pInstance - Instance Handle
  * @param[in] nErrorMessageBufferSize - size of the buffer (including trailing 0)
  * @param[out] pErrorMessageNeededChars - will be filled with the count of the written bytes, or needed buffer size.
  * @param[out] pErrorMessageBuffer -  buffer of Message of the last error, may be NULL
  * @param[out] pHasError - Is there a last error to query
  * @return error code or 0 (success)
  *)
  TNumbersGetLastErrorFunc = function(const pInstance: TNumbersHandle; const nErrorMessageBufferSize: Cardinal; out pErrorMessageNeededChars: Cardinal; pErrorMessageBuffer: PAnsiChar; out pHasError: Byte): TNumbersResult; cdecl;
  
  (**
  * Releases shared ownership of an Instance
  *
  * @param[in] pInstance - Instance Handle
  * @return error code or 0 (success)
  *)
  TNumbersReleaseInstanceFunc = function(const pInstance: TNumbersHandle): TNumbersResult; cdecl;
  
  (**
  * Acquires shared ownership of an Instance
  *
  * @param[in] pInstance - Instance Handle
  * @return error code or 0 (success)
  *)
  TNumbersAcquireInstanceFunc = function(const pInstance: TNumbersHandle): TNumbersResult; cdecl;
  
  (**
  * Returns the address of the SymbolLookupMethod
  *
  * @param[out] pSymbolLookupMethod - Address of the SymbolAddressMethod
  * @return error code or 0 (success)
  *)
  TNumbersGetSymbolLookupMethodFunc = function(out pSymbolLookupMethod: Pointer): TNumbersResult; cdecl;
  

(*************************************************************************************************************************
 Helper function pointer definitions 
**************************************************************************************************************************)
TNumbersSymbolLookupMethod = function(const pSymbolName: PAnsiChar; out pValue: Pointer): TNumbersResult; cdecl;

(*************************************************************************************************************************
 Exception definition
**************************************************************************************************************************)

  ENumbersException = class(Exception)
  private
    FErrorCode: TNumbersResult;
    FCustomMessage: String;
  public
    property ErrorCode: TNumbersResult read FErrorCode;
    property CustomMessage: String read FCustomMessage;
    constructor Create(AErrorCode: TNumbersResult; AMessage: String);
    constructor CreateCustomMessage(AErrorCode: TNumbersResult; AMessage: String);
  end;


(*************************************************************************************************************************
 Class definition for Base
**************************************************************************************************************************)

 TNumbersBase = class(TObject)
  private
    FWrapper: TNumbersWrapper;
    FHandle: TNumbersHandle;
  public
    constructor Create(AWrapper: TNumbersWrapper; AHandle: TNumbersHandle);
    destructor Destroy; override;
    property TheHandle: TNumbersHandle read FHandle;
    function ClassTypeId(): QWord;
  end;


(*************************************************************************************************************************
 Class definition for Variable
**************************************************************************************************************************)

  TNumbersVariable = class(TNumbersBase)
  public
    constructor Create(AWrapper: TNumbersWrapper; AHandle: TNumbersHandle);
    destructor Destroy; override;
    function GetValue(): Double;
    procedure SetValue(const AValue: Double);
  end;

(*************************************************************************************************************************
 Wrapper definition
**************************************************************************************************************************)

  TNumbersWrapper = class(TObject)
  private
    FModule: HMODULE;
    FNumbersBase_ClassTypeIdFunc: TNumbersBase_ClassTypeIdFunc;
    FNumbersVariable_GetValueFunc: TNumbersVariable_GetValueFunc;
    FNumbersVariable_SetValueFunc: TNumbersVariable_SetValueFunc;
    FNumbersCreateVariableFunc: TNumbersCreateVariableFunc;
    FNumbersGetVersionFunc: TNumbersGetVersionFunc;
    FNumbersGetLastErrorFunc: TNumbersGetLastErrorFunc;
    FNumbersReleaseInstanceFunc: TNumbersReleaseInstanceFunc;
    FNumbersAcquireInstanceFunc: TNumbersAcquireInstanceFunc;
    FNumbersGetSymbolLookupMethodFunc: TNumbersGetSymbolLookupMethodFunc;

    {$IFDEF MSWINDOWS}
    function LoadFunction(AFunctionName: AnsiString; FailIfNotExistent: Boolean = True): FARPROC;
    {$ELSE}
    function LoadFunction(AFunctionName: AnsiString; FailIfNotExistent: Boolean = True): Pointer;
    {$ENDIF MSWINDOWS}

    procedure checkBinaryVersion();

  protected
    property NumbersBase_ClassTypeIdFunc: TNumbersBase_ClassTypeIdFunc read FNumbersBase_ClassTypeIdFunc;
    property NumbersVariable_GetValueFunc: TNumbersVariable_GetValueFunc read FNumbersVariable_GetValueFunc;
    property NumbersVariable_SetValueFunc: TNumbersVariable_SetValueFunc read FNumbersVariable_SetValueFunc;
    property NumbersCreateVariableFunc: TNumbersCreateVariableFunc read FNumbersCreateVariableFunc;
    property NumbersGetVersionFunc: TNumbersGetVersionFunc read FNumbersGetVersionFunc;
    property NumbersGetLastErrorFunc: TNumbersGetLastErrorFunc read FNumbersGetLastErrorFunc;
    property NumbersReleaseInstanceFunc: TNumbersReleaseInstanceFunc read FNumbersReleaseInstanceFunc;
    property NumbersAcquireInstanceFunc: TNumbersAcquireInstanceFunc read FNumbersAcquireInstanceFunc;
    property NumbersGetSymbolLookupMethodFunc: TNumbersGetSymbolLookupMethodFunc read FNumbersGetSymbolLookupMethodFunc;
    procedure CheckError(AInstance: TNumbersBase; AErrorCode: TNumbersResult);
  public
    constructor Create(ADLLName: String);
    constructor CreateFromSymbolLookupMethod(ALookupMethod: TNumbersSymbolLookupMethod);
    destructor Destroy; override;
    function CreateVariable(const AInitialValue: Double): TNumbersVariable;
    procedure GetVersion(out AMajor: Cardinal; out AMinor: Cardinal; out AMicro: Cardinal);
    function GetLastError(const AInstance: TNumbersBase; out AErrorMessage: String): Boolean;
    procedure ReleaseInstance(const AInstance: TNumbersBase);
    procedure AcquireInstance(const AInstance: TNumbersBase);
    function GetSymbolLookupMethod(): Pointer;
  end;

  TNumbersPolymorphicFactory<_T:class; _B> = record
    class function Make(Wrapper: TNumbersWrapper; Handle: TNumbersHandle): _T; static;
  end;
  function TNumbersPolymorphicFactoryMakeBase(Wrapper: TNumbersWrapper; Handle: TNumbersHandle): TNUMBERSBase;
  function TNumbersPolymorphicFactoryMakeVariable(Wrapper: TNumbersWrapper; Handle: TNumbersHandle): TNUMBERSVariable;

implementation


(*************************************************************************************************************************
 PolymorficFactory implementation
**************************************************************************************************************************)

  (**
   * IMPORTANT: PolymorphicFactory method should not be used by application directly.
   *            It's designed to be used on NumbersHandle object only once.
   *            If it's used on any existing object as a form of dynamic cast then
   *            TNUMBERSWrapper::AcquireInstance(object: TNUMBERSBase) must be called after instantiating new object.
   *            This is important to keep reference count matching between application and library sides.
  *)
  class function TNumbersPolymorphicFactory<_T, _B>.Make(Wrapper: TNumbersWrapper; Handle: TNumbersHandle): _T;
  var
    ClassTypeId: QWord;
    Obj: TNUMBERSBase;
  begin
    Result := nil;
    Wrapper.CheckError(nil, Wrapper.NumbersBase_ClassTypeIdFunc(handle, ClassTypeId));
    case (ClassTypeId) of
      QWord($27799F69B3FD1C9E): begin Obj := TNUMBERSBase.Create(Wrapper, Handle); if Obj.inheritsFrom(_T) then Result := Obj as _T; end; // First 64 bits of SHA1 of a string: "Numbers::Base"
      QWord($23934EDF762423EA): begin Obj := TNUMBERSVariable.Create(Wrapper, Handle); if Obj.inheritsFrom(_T) then Result := Obj as _T; end; // First 64 bits of SHA1 of a string: "Numbers::Variable"
    end;
    if Result = nil then Result := _B.Create(Wrapper, Handle);
  end;
  function TNumbersPolymorphicFactoryMakeBase(Wrapper: TNumbersWrapper; Handle: TNumbersHandle): TNUMBERSBase;
  begin
    Result := TNumbersPolymorphicFactory<TNUMBERSBase, TNUMBERSBase>.Make(Wrapper, Handle);
  end;
  function TNumbersPolymorphicFactoryMakeVariable(Wrapper: TNumbersWrapper; Handle: TNumbersHandle): TNUMBERSVariable;
  begin
    Result := TNumbersPolymorphicFactory<TNUMBERSVariable, TNUMBERSVariable>.Make(Wrapper, Handle);
  end;

(*************************************************************************************************************************
 Exception implementation
**************************************************************************************************************************)

  constructor ENumbersException.Create(AErrorCode: TNumbersResult; AMessage: String);
  var
    ADescription: String;
  begin
    FErrorCode := AErrorCode;
    case FErrorCode of
      NUMBERS_ERROR_NOTIMPLEMENTED: ADescription := 'functionality not implemented';
      NUMBERS_ERROR_INVALIDPARAM: ADescription := 'an invalid parameter was passed';
      NUMBERS_ERROR_INVALIDCAST: ADescription := 'a type cast failed';
      NUMBERS_ERROR_BUFFERTOOSMALL: ADescription := 'a provided buffer is too small';
      NUMBERS_ERROR_GENERICEXCEPTION: ADescription := 'a generic exception occurred';
      NUMBERS_ERROR_COULDNOTLOADLIBRARY: ADescription := 'the library could not be loaded';
      NUMBERS_ERROR_COULDNOTFINDLIBRARYEXPORT: ADescription := 'a required exported symbol could not be found in the library';
      NUMBERS_ERROR_INCOMPATIBLEBINARYVERSION: ADescription := 'the version of the binary interface does not match the bindings interface';
      else
        ADescription := 'unknown';
    end;

    inherited Create(Format('Numbers library Error - %s (#%d, %s)', [ ADescription, AErrorCode, AMessage ]));
  end;

  constructor ENumbersException.CreateCustomMessage(AErrorCode: TNumbersResult; AMessage: String);
  begin
    FCustomMessage := AMessage;
    FErrorCode := AErrorCode;
    inherited Create(Format('%s (%d)', [FCustomMessage, AErrorCode]));
  end;

(*************************************************************************************************************************
 Class implementation for Base
**************************************************************************************************************************)

  constructor TNumbersBase.Create(AWrapper: TNumbersWrapper; AHandle: TNumbersHandle);
  begin
    if not Assigned(AWrapper) then
      raise ENumbersException.Create(NUMBERS_ERROR_INVALIDPARAM, '');
    if not Assigned(AHandle.Handle) then
      raise ENumbersException.Create(NUMBERS_ERROR_INVALIDPARAM, '');

    inherited Create();
    FWrapper := AWrapper;
    FHandle := AHandle;
  end;

  destructor TNumbersBase.Destroy;
  begin
    FWrapper.ReleaseInstance(self);
    inherited;
  end;

  function TNumbersBase.ClassTypeId(): QWord;
  begin
    FWrapper.CheckError(Self, FWrapper.NumbersBase_ClassTypeIdFunc(FHandle, Result));
  end;

(*************************************************************************************************************************
 Class implementation for Variable
**************************************************************************************************************************)

  constructor TNumbersVariable.Create(AWrapper: TNumbersWrapper; AHandle: TNumbersHandle);
  begin
    inherited Create(AWrapper, AHandle);
  end;

  destructor TNumbersVariable.Destroy;
  begin
    inherited;
  end;

  function TNumbersVariable.GetValue(): Double;
  begin
    FWrapper.CheckError(Self, FWrapper.NumbersVariable_GetValueFunc(FHandle, Result));
  end;

  procedure TNumbersVariable.SetValue(const AValue: Double);
  begin
    FWrapper.CheckError(Self, FWrapper.NumbersVariable_SetValueFunc(FHandle, AValue));
  end;

(*************************************************************************************************************************
 Wrapper class implementation
**************************************************************************************************************************)

  constructor TNumbersWrapper.Create(ADLLName: String);
  {$IFDEF MSWINDOWS}
  var
    AWideString: WideString;
  {$ENDIF MSWINDOWS}
  begin
    inherited Create;
    
    
    {$IFDEF MSWINDOWS}
      AWideString := UTF8Decode(ADLLName + #0);
      FModule := LoadLibraryW(PWideChar(AWideString));
    {$ELSE}
      FModule := dynlibs.LoadLibrary(ADLLName);
    {$ENDIF MSWINDOWS}
    if FModule = 0 then
      raise ENumbersException.Create(NUMBERS_ERROR_COULDNOTLOADLIBRARY, '');

    FNumbersBase_ClassTypeIdFunc := LoadFunction('numbers_base_classtypeid');
    FNumbersVariable_GetValueFunc := LoadFunction('numbers_variable_getvalue');
    FNumbersVariable_SetValueFunc := LoadFunction('numbers_variable_setvalue');
    FNumbersCreateVariableFunc := LoadFunction('numbers_createvariable');
    FNumbersGetVersionFunc := LoadFunction('numbers_getversion');
    FNumbersGetLastErrorFunc := LoadFunction('numbers_getlasterror');
    FNumbersReleaseInstanceFunc := LoadFunction('numbers_releaseinstance');
    FNumbersAcquireInstanceFunc := LoadFunction('numbers_acquireinstance');
    FNumbersGetSymbolLookupMethodFunc := LoadFunction('numbers_getsymbollookupmethod');
    
    checkBinaryVersion();
  end;

  constructor TNumbersWrapper.CreateFromSymbolLookupMethod(ALookupMethod: TNumbersSymbolLookupMethod);
  var
    AResult : TNumbersResult;
  begin
    inherited Create;
    
    
    AResult := ALookupMethod(PAnsiChar('numbers_base_classtypeid'), @FNumbersBase_ClassTypeIdFunc);
    if AResult <> NUMBERS_SUCCESS then
      raise ENumbersException.CreateCustomMessage(NUMBERS_ERROR_COULDNOTLOADLIBRARY, '');
    AResult := ALookupMethod(PAnsiChar('numbers_variable_getvalue'), @FNumbersVariable_GetValueFunc);
    if AResult <> NUMBERS_SUCCESS then
      raise ENumbersException.CreateCustomMessage(NUMBERS_ERROR_COULDNOTLOADLIBRARY, '');
    AResult := ALookupMethod(PAnsiChar('numbers_variable_setvalue'), @FNumbersVariable_SetValueFunc);
    if AResult <> NUMBERS_SUCCESS then
      raise ENumbersException.CreateCustomMessage(NUMBERS_ERROR_COULDNOTLOADLIBRARY, '');
    AResult := ALookupMethod(PAnsiChar('numbers_createvariable'), @FNumbersCreateVariableFunc);
    if AResult <> NUMBERS_SUCCESS then
      raise ENumbersException.CreateCustomMessage(NUMBERS_ERROR_COULDNOTLOADLIBRARY, '');
    AResult := ALookupMethod(PAnsiChar('numbers_getversion'), @FNumbersGetVersionFunc);
    if AResult <> NUMBERS_SUCCESS then
      raise ENumbersException.CreateCustomMessage(NUMBERS_ERROR_COULDNOTLOADLIBRARY, '');
    AResult := ALookupMethod(PAnsiChar('numbers_getlasterror'), @FNumbersGetLastErrorFunc);
    if AResult <> NUMBERS_SUCCESS then
      raise ENumbersException.CreateCustomMessage(NUMBERS_ERROR_COULDNOTLOADLIBRARY, '');
    AResult := ALookupMethod(PAnsiChar('numbers_releaseinstance'), @FNumbersReleaseInstanceFunc);
    if AResult <> NUMBERS_SUCCESS then
      raise ENumbersException.CreateCustomMessage(NUMBERS_ERROR_COULDNOTLOADLIBRARY, '');
    AResult := ALookupMethod(PAnsiChar('numbers_acquireinstance'), @FNumbersAcquireInstanceFunc);
    if AResult <> NUMBERS_SUCCESS then
      raise ENumbersException.CreateCustomMessage(NUMBERS_ERROR_COULDNOTLOADLIBRARY, '');
    AResult := ALookupMethod(PAnsiChar('numbers_getsymbollookupmethod'), @FNumbersGetSymbolLookupMethodFunc);
    if AResult <> NUMBERS_SUCCESS then
      raise ENumbersException.CreateCustomMessage(NUMBERS_ERROR_COULDNOTLOADLIBRARY, '');
    
    checkBinaryVersion();
  end;

  destructor TNumbersWrapper.Destroy;
  begin
    {$IFDEF MSWINDOWS}
      if FModule <> 0 then
        FreeLibrary(FModule);
    {$ELSE}
      if FModule <> 0 then
        UnloadLibrary(FModule);
    {$ENDIF MSWINDOWS}
    inherited;
  end;

  procedure TNumbersWrapper.CheckError(AInstance: TNumbersBase; AErrorCode: TNumbersResult);
  var
    AErrorMessage: String;
  begin
    if AInstance <> nil then begin
      if AInstance.FWrapper <> Self then
        raise ENumbersException.CreateCustomMessage(NUMBERS_ERROR_INVALIDCAST, 'invalid wrapper call');
    end;
    if AErrorCode <> NUMBERS_SUCCESS then begin
      AErrorMessage := '';
      if Assigned(AInstance) then
        GetLastError(AInstance, AErrorMessage);
      raise ENumbersException.Create(AErrorCode, AErrorMessage);
    end;
  end;

  {$IFDEF MSWINDOWS}
  function TNumbersWrapper.LoadFunction(AFunctionName: AnsiString; FailIfNotExistent: Boolean): FARPROC;
  begin
    Result := GetProcAddress(FModule, PAnsiChar(AFunctionName));
    if FailIfNotExistent and not Assigned(Result) then
      raise ENumbersException.CreateCustomMessage(NUMBERS_ERROR_COULDNOTFINDLIBRARYEXPORT, 'could not find function ' + AFunctionName);
  end;
  {$ELSE}
  function TNumbersWrapper.LoadFunction(AFunctionName: AnsiString; FailIfNotExistent: Boolean): Pointer;
  begin
    Result := dynlibs.GetProcAddress(FModule, AFunctionName);
    if FailIfNotExistent and not Assigned(Result) then
      raise ENumbersException.CreateCustomMessage(NUMBERS_ERROR_COULDNOTFINDLIBRARYEXPORT, 'could not find function ' + AFunctionName);
  end;
  {$ENDIF MSWINDOWS}

  procedure TNumbersWrapper.checkBinaryVersion();
  var
    AMajor, AMinor, AMicro: Cardinal;
  begin
    GetVersion(AMajor, AMinor, AMicro);
    if (AMajor <> NUMBERS_VERSION_MAJOR) then
      raise ENumbersException.Create(NUMBERS_ERROR_INCOMPATIBLEBINARYVERSION, '');
  end;
  
  function TNumbersWrapper.CreateVariable(const AInitialValue: Double): TNumbersVariable;
  var
    HInstance: TNumbersHandle;
  begin
    Result := nil;
    HInstance.Handle := nil;
    HInstance.ClassTypeId := 0;
    CheckError(nil, NumbersCreateVariableFunc(AInitialValue, HInstance));
    if Assigned(HInstance.Handle) then
      Result := TNumbersPolymorphicFactory<TNumbersVariable, TNumbersVariable>.Make(Self, HInstance);
  end;

  procedure TNumbersWrapper.GetVersion(out AMajor: Cardinal; out AMinor: Cardinal; out AMicro: Cardinal);
  begin
    CheckError(nil, NumbersGetVersionFunc(AMajor, AMinor, AMicro));
  end;

  function TNumbersWrapper.GetLastError(const AInstance: TNumbersBase; out AErrorMessage: String): Boolean;
  var
    AInstanceHandle: TNumbersHandle;
    bytesNeededErrorMessage: Cardinal;
    bytesWrittenErrorMessage: Cardinal;
    bufferErrorMessage: array of Char;
    ResultHasError: Byte;
  begin
    if Assigned(AInstance) then
    AInstanceHandle := AInstance.TheHandle
    else
      raise ENumbersException.CreateCustomMessage(NUMBERS_ERROR_INVALIDPARAM, 'AInstance is a nil value.');
    bytesNeededErrorMessage:= 0;
    bytesWrittenErrorMessage:= 0;
    ResultHasError := 0;
    CheckError(nil, NumbersGetLastErrorFunc(AInstanceHandle, 0, bytesNeededErrorMessage, nil, ResultHasError));
    SetLength(bufferErrorMessage, bytesNeededErrorMessage);
    CheckError(nil, NumbersGetLastErrorFunc(AInstanceHandle, bytesNeededErrorMessage, bytesWrittenErrorMessage, @bufferErrorMessage[0], ResultHasError));
    AErrorMessage := StrPas(@bufferErrorMessage[0]);
    Result := (ResultHasError <> 0);
  end;

  procedure TNumbersWrapper.ReleaseInstance(const AInstance: TNumbersBase);
  var
    AInstanceHandle: TNumbersHandle;
  begin
    if Assigned(AInstance) then
    AInstanceHandle := AInstance.TheHandle
    else
      raise ENumbersException.CreateCustomMessage(NUMBERS_ERROR_INVALIDPARAM, 'AInstance is a nil value.');
    CheckError(nil, NumbersReleaseInstanceFunc(AInstanceHandle));
  end;

  procedure TNumbersWrapper.AcquireInstance(const AInstance: TNumbersBase);
  var
    AInstanceHandle: TNumbersHandle;
  begin
    if Assigned(AInstance) then
    AInstanceHandle := AInstance.TheHandle
    else
      raise ENumbersException.CreateCustomMessage(NUMBERS_ERROR_INVALIDPARAM, 'AInstance is a nil value.');
    CheckError(nil, NumbersAcquireInstanceFunc(AInstanceHandle));
  end;

  function TNumbersWrapper.GetSymbolLookupMethod(): Pointer;
  begin
    CheckError(nil, NumbersGetSymbolLookupMethodFunc(Result));
  end;


end.
