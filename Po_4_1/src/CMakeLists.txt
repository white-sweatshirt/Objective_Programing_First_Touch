add_library( DivisonOfBank 
     DivisonOfBank.cpp people.cpp account.cpp
)
target_include_directories(DivisonOfBank PUBLIC ${headersFolder})