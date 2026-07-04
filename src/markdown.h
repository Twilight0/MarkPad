#ifndef MARKYD_MARKDOWN_H
#define MARKYD_MARKDOWN_H

#include <gtk/gtk.h>

/* GObject data key used to mark hrule child anchors inserted into the buffer. */
#define MARKPAD_HRULE_ANCHOR_DATA "markpad-hr-anchor"

/* Initialize markdown tags on a text buffer */
void markdown_init_tags(GtkTextBuffer *buffer);

/* Update accent colors for existing tags (after config changes). */
void markdown_update_accent_tags(GtkTextBuffer *buffer);

/* Data key set on per-link metadata tags to store resolved URL/href. */
#define MARKPAD_LINK_URL_DATA "markpad-link-url"

/* Prefix for named text marks used as internal heading anchors. */
#define MARKPAD_ANCHOR_MARK_PREFIX "markpad-anchor-"

/* GObject data key used to mark table child anchors with parsed table data. */
#define MARKPAD_TABLE_ANCHOR_DATA "markpad-table-anchor"
/* GObject data key set on table anchors for hidden searchable index metadata. */
#define MARKPAD_TABLE_SEARCH_INDEX_DATA "markpad-table-search-index"
/* GObject data key set on table anchors for attached table widget instance. */
#define MARKPAD_TABLE_WIDGET_DATA "markpad-table-widget"
/* GObject data keys set on each table cell widget. */
#define MARKPAD_TABLE_CELL_ROW_DATA "markpad-table-cell-row"
#define MARKPAD_TABLE_CELL_COL_DATA "markpad-table-cell-col"
/* CSS classes for table search highlight states. */
#define MARKPAD_TABLE_CELL_MATCH_CLASS "markpad-table-cell-match"
#define MARKPAD_TABLE_CELL_CURRENT_CLASS "markpad-table-cell-current"

/* GObject data keys for image anchors and metadata. */
#define MARKPAD_IMAGE_ANCHOR_DATA "markpad-image-anchor"
#define MARKPAD_IMAGE_SRC_DATA "markpad-image-src"
#define MARKPAD_IMAGE_ALT_DATA "markpad-image-alt"
#define MARKPAD_IMAGE_WIDGET_DATA "markpad-image-widget"

typedef struct {
  gint row;
  gint col;
  gint start_offset;
  gint end_offset;
} MarkpadTableSearchCellRange;

typedef struct {
  gint start_offset;
  gint end_offset;
  GArray *cells; /* MarkpadTableSearchCellRange */
} MarkpadTableSearchIndex;

/* Normalize heading/link text into anchor slug form. Caller owns result. */
gchar *markdown_normalize_anchor_slug(const gchar *text);

/* Build full text-mark name for an anchor fragment. Caller owns result. */
gchar *markdown_anchor_mark_name(const gchar *fragment);

/* Render markdown source into the buffer and apply markdown styling. */
void markdown_apply_tags(GtkTextBuffer *buffer, const gchar *source);

/* Build a GTK widget for a table anchor, or NULL if not a table anchor. */
GtkWidget *markdown_create_table_widget(GtkTextChildAnchor *anchor);

#endif /* MARKYD_MARKDOWN_H */
