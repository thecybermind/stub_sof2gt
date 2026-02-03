for %%x in (SOF2MP) do (
    msbuild .\msvc\stub_sof2gt.vcxproj /p:Configuration=Debug-%%x /p:Platform=x86
)
