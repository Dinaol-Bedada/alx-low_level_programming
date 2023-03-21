import ctypes

# Load the dynamic library
lib = ctypes.cdll.LoadLibrary('./100-operations.so')

# Define the argument and return types for each function
lib.add.argtypes = (ctypes.c_float, ctypes.c_float)
lib.add.restype = ctypes.c_float
lib.subtract.argtypes = (ctypes.c_float, ctypes.c_float)
lib.subtract.restype = ctypes.c_float
lib.multiply.argtypes = (ctypes.c_float, ctypes.c_float)
lib.multiply.restype = ctypes.c_float
lib.divide.argtypes = (ctypes.c_float, ctypes.c_float)
lib.divide.restype = ctypes.c_float

# Define Python functions that call the C functions
def add(a, b):
    return lib.add(a, b)

def subtract(a, b):
    return lib.subtract(a, b)

def multiply(a, b):
    return lib.multiply(a, b)

def divide(a, b):
    return lib.divide(a, b)
