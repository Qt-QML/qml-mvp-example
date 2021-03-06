#include "qml_item_view.h"

#include <QtQuick>

QmlItemView::QmlItemView():
    QQuickItemView()
{}

void QmlItemView::createVisualItem(QQuickItem* parentItem)
{
    QQmlComponent component(qmlEngine(parentItem), this->source());
    m_item = qobject_cast<QQuickItem*>(component.create());
    m_item->setParentItem(parentItem);
    QQmlEngine::setObjectOwnership(m_item, QQmlEngine::JavaScriptOwnership);
}

QUrl QmlItemView::source() const
{
    return m_source;
}

void QmlItemView::setSource(const QUrl& source)
{
    m_source = source;

    if (m_item)
    {
        this->createVisualItem(qobject_cast<QQuickItem*>(m_item->parent()));
    }
}

