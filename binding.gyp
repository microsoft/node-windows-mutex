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
      'msvs_settings': {
        'VCCLCompilerTool': {
          'AdditionalOptions': [
            '/Qspectre',
            '/guard:cf',
            '/ZH:SHA_256'
            '/w34244',
            '/w34267',
            '/sdl'
          ]
        },
        'VCLinkerTool': {
          'AdditionalOptions': [
            '/guard:cf',
            '/CEFCOMPAT',
            '/DYNAMICBASE'
          ]
        }
      }
    }
  ]
}