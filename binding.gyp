{
  "targets": [
    {
      "target_name": "CreateMutex",
      "dependencies": [
        "<!(node -p \"require('node-addon-api').targets\"):node_addon_api_except",
      ],
      "conditions": [
        ['OS=="win"', {
          "sources": [
            "src/main.cc",
            "src/mutex.cc"
          ],
          "include_dirs" : [],
          'msvs_configuration_attributes': {
            'SpectreMitigation': 'Spectre'
          },
          'msvs_settings': {
            'VCCLCompilerTool': {
              'AdditionalOptions': [
                '/guard:cf',
                '/W3',
                '/w34244',
                '/w34267',
                '/ZH:SHA_256'
              ]
            },
            'VCLinkerTool': {
              'AdditionalOptions': [
                '/DYNAMICBASE',
                '/guard:cf'
              ]
            }
          }
        }]
      ]
    }
  ]
}