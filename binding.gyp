{
  "targets": [
    {
      "target_name": "CreateMutex",
      "conditions": [
        ['OS=="win"', {
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
                '/W3',
                '/w34244',
                '/w34267'
              ]
            },
            'VCLinkerTool': {
              'AdditionalOptions': [
                '/guard:cf'
              ]
            }
          }
        }]
      ]
    }
  ]
}