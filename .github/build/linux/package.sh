#!/bin/sh
mkdir -p package
cd package
rm -f *
cp ../README.md ./
cp ../LICENSE ./

#for f in SOF2MP; do
#  cp ../bin/release-$f/x86/stub_sof2gt_$f.so ./
#done

cd ..
