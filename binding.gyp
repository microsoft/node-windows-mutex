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
      "msvs_settings": {
        "VCCLCompilerTool": {
          "AdditionalOptions": [
            "-std:c++17"
          ]
        }
      }
    }
  ]
}