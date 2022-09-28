{
  "targets": [
    {
      "target_name": "CreateMutex",
      "sources": [
        "src/main.cc",
        "src/mutex.cc"
      ],
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ],
      "conditions": [
        ['OS=="mac"', {
          "xcode_settings": {
            "CLANG_CXX_LANGUAGE_STANDARD": "c++17"
          }
        }],
        ['OS=="win"', {
          "msvs_settings": {
            "VCCLCompilerTool": {
              "AdditionalOptions": [ "-std:c++17", ],
            },
          },
        }]
      ]
    }
  ]
}