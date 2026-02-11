mkdir package
pushd package
del /q *
rem copy ..\README.md .\
rem copy ..\LICENSE .\

for %%G in (SOF2MP) do (
    copy ..\bin\Release-%%G\x86\stub_sof2gt_%%G.dll .\
)
popd
