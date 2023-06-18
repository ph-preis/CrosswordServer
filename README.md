# Crossword generator server

#### Purpose
A server for providing crossword puzzles.

#### Status
The server is working, but for now it only provides just a single predefined crossword. This is obviously a bit boring - in the future it should auto-generate new crossword puzzles. 

#### Architecture

This project is mostly a tech demo. It shows how to integrate the following components
- Meson build system
- GTK
- Restbed
- OpenAPI-generator

It was only tested on Linux but might also work on other operating systems.

#### Compiling

Get the Meson build system:

https://mesonbuild.com/Quick-guide.html

If you're using CLion, follow this article to use Meson:

https://blog.jetbrains.com/clion/2021/01/working-with-meson-in-clion-using-compilation-db/

Install GTK and Boost library:

``sudo apt-get install build-essential libgtk-3-dev``

``sudo apt-get install libboost-all-dev``


The Restbed server was pre-built and is located in the /restbed directory. To rebuild or update, follow the instructions at:
https://github.com/Corvusoft/restbed

Proceed with the usual Meson build steps:

``user@computer:/xxxxx/CrosswordServer$ meson setup builddir && cd builddir``

``user@computer:/xxxxx/CrosswordServer/builddir$ meson compile``

When modifying the OpenAPI definitions in /openapi/crossword.yml, the API (restbed server code) needs to be re-generated. Get openapi-generator-cli.jar from https://github.com/OpenAPITools/openapi-generator and install Java (if needed), then run:

``user@computer:/xxxxx/CrosswordServer$ java -jar openapi-generator-cli.jar generate -g cpp-restbed-server -o openapi/server -i openapi/crosswords.yml``

There may be a compile error in DefaultAPI::extractBodyContent after re-generating the API. In that case, change the error line to:

``int content_length;``

``request->get_header("Content-Length", content_length);``
