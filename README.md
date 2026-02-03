# Stub_SoF2GT
Stub_SoF2GT - Example stub plugin for SOF2GT_QMM  
Copyright 2025-2026  
https://github.com/thecybermind/stub_sof2gt/  
3-clause BSD license: https://opensource.org/license/bsd-3-clause  

Created By: Kevin Masterson < k.m.masterson@gmail.com >

---

Soldier of Fortune 2 provides a system for even smaller dynamic modifications, in the form of a "gametype" file. This is available as a DLL/SO or as a QVM.

The [SoF2GT_QMM plugin](https://github.com/thecybermind/sof2gt_qmm/) intercepts this load and provides GT_vmMain + GT_syscall hooks to other QMM plugins using the QMM plugin message system.

This plugin uses these additional hooks and is modeled after the [Stub_QMM plugin](https://github.com/thecybermind/stub_qmm/) in that it shows all the calls that run through the hooked gametype interface.


1. Install QMM ( https://github.com/thecybermind/qmm2/wiki/Installation )
2. Make a qmmaddons/stub_sof2gt directory inside your mod directory and place stub_sof2gt.dll here
3. Add the path to stub_sof2gt.dll as an entry in the plugins list in qmm2.json
