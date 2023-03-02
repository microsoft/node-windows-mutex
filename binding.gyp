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
      'msvs_configuration_attributes': {
        'SpectreMitigation': 'Spectre'
      },
      'msvs_settings': {
        'VCCLCompilerTool': {
          'AdditionalOptions': [
            '/guard:cf',
            '/ZH:SHA_256',
            '/we4244',
            '/we4267'
          ]
        },
        'VCLinkerTool': {
          'AdditionalOptions': [
            '/guard:cf'
          ]
        }
      }
    }
  ]
}