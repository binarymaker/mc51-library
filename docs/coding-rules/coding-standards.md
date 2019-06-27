# Coding Standards

+ A line of code shall not exceed 80 characters including the
  terminal characters.

+ The function prototypes shall include the variable names and not
  just the data type.  Rationale It makes it easy to understand what
  the function requires by reading the prototype.

+ Function name shall always start with the filename in which it
  is located.

+ Predefined static variables shall not be initialised during
  declaration. It shall be written by the init function.

+ Only one variable shall be declared per line of code.

+ Macros shall be declared only using upper case characters.

+ Variables shall the following prefix depending on the variable
  type.

  + u8_ unsigned 8 bit variable
  + u16_ unsigned 16 bit variable
  + u32_ unsigned 32 bit variable
  + i8_ signed 8 bit variable
  + i16_ signed 16 bit variable
  + i32_ signed 32 bit variable

+ Variables shall be declared with the following type definitions.

  + uint8_t unsigned 8 bit variable
  + uint16_t unsigned 16 bit variab
  + uint32_t unsigned 32 bit variable
  + int8_t signed 8 bit variable
  + int16_t signed 16 bit variable
  + int32_t signed 32 bit variable

+ While declaring functions, 'Return type' of a function shall be
  written in the first line and the 'function name' and parameters
  shall be written in subsequent lines.

+ Name of a structure declaration shall be suffixed with _s.

+ Name of a typedef shall end be suffixed with _t.

+ Typedef for a structure shall be suffixed with _struct_t.

+ Typedef for a union shall be suffixed with _union_t.

+ Filenames should use hyphens over underscores as demarkers and
  shall not have any special characters.

+ Filenames shall use only lowercase characters.

+ Usage of global variables should be avoided.

+ Global variables shall be contained within a file using the
  static qualifier.

+ Files shall be created using smake only.
