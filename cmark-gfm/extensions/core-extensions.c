#include "cmark-gfm-core-extensions.h"
#include "autolink.h"
#include "strikethrough.h"
#include "table.h"
#include "tagfilter.h"
#include "tasklist.h"
#include "registry.h"
#include "plugin.h"

#include "mention.h"
// #include "checkbox.h"
#include "syntaxhighlight.h"
#include "inlineimage.h"
#include "emoji.h"
#include "heads.h"

static int core_extensions_registration(cmark_plugin *plugin) {
  cmark_plugin_register_syntax_extension(plugin, create_table_extension());
  cmark_plugin_register_syntax_extension(plugin,
                                         create_strikethrough_extension());
  cmark_plugin_register_syntax_extension(plugin, create_autolink_extension());
  cmark_plugin_register_syntax_extension(plugin, create_tagfilter_extension());
  cmark_plugin_register_syntax_extension(plugin, create_tasklist_extension());
    
    
  cmark_plugin_register_syntax_extension(plugin, create_mention_extension());
  //cmark_plugin_register_syntax_extension(plugin, create_checkbox_extension());
  cmark_plugin_register_syntax_extension(plugin, create_inlineimage_extension());
    
  cmark_plugin_register_syntax_extension(plugin, create_syntaxhighlight_extension());
    
  cmark_plugin_register_syntax_extension(plugin, create_emoji_extension());
    cmark_plugin_register_syntax_extension(plugin, create_heads_extension());
  return 1;
}

void cmark_gfm_core_extensions_ensure_registered(void) {
  static int registered = 0;

  if (!registered) {
    cmark_register_plugin(core_extensions_registration);
    registered = 1;
  }
}
