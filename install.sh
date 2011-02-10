cd vpd-src
make
cd ..
cd vpclient-src
make
cd ..
cp vpd-src/bin/Release/vpd .
cp vpclient-src/bin/Release/vpclient .
touch ~/vpd.txt
echo "4" >> vpd.txt
echo "4" >> vpd.txt
echo "10" >> vpd.txt
echo "1" >> vpd.txt