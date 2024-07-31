# Multi Level Hashing
A multi level hashing system using OpenSSL. \
## A word for contributors
If you are a developer, make a branch from `multihash_dev` branch for your development. Once you are done, do a PR to `multihash_dev` branch and select me as a reviewer. I'll merge the changes. \
This is a Visual Studio Solution. I used VS 2022 for all the developments\
This repo incldes all the libraries needed. OpenSSL 3.3.1 is statically linked to the project and OpenSSL library folder is in the project folder.\
If you are going to use older version of OpenSSL (Which I do not recommend), build OpenSSL with `no-shared` option and replace the OpenSSL folder content with yours. But when you are doing the changes to the codebase use the most recent verion of OpenSSL. But ofcourse you can always test with older versions.\
A unit testing project using Google Test, has also been inititalized to this solution. But haven't developed any test cases yet.
