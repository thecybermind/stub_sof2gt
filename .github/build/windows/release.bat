for %%G in (SOF2MP) do (
    msbuild .\msvc\stub_sof2gt.vcxproj /p:Configuration=Release-%%G /p:Platform=x86
)
