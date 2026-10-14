#!/bin/sh
mkdir -p package
cd package
rm -f *
cp ../README.md ./
cp ../LICENSE ./

cp ../bin/release/x86/stub_sof2gt.so ./

cd ..
