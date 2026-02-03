mkdir package
pushd package
del /q *
rem copy ..\README.md .\
rem copy ..\LICENSE .\

for %%x in (SOF2MP) do (
    copy ..\bin\Release-%%x\x86\stub_sof2gt_%%x.dll .\
    copy ..\bin\Release-%%x\x64\stub_sof2gt_x86_64_%%x.dll .\     
)
popd
