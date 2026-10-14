mkdir package
pushd package
del /q *
rem copy ..\README.md .\
rem copy ..\LICENSE .\

copy ..\bin\Release\x86\stub_sof2gt.dll .\  

popd
