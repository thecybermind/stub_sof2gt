for %%x in (SOF2MP) do (
    msbuild .\msvc\stub_sof2gt.vcxproj /p:Configuration=Release-%%x /p:Platform=x86
    msbuild .\msvc\stub_sof2gt.vcxproj /p:Configuration=Release-%%x /p:Platform=x64
)
