for %%G in (SOF2MP) do (
    msbuild .\msvc\stub_sof2gt.vcxproj /p:Configuration=Debug-%%G /p:Platform=x86
)
